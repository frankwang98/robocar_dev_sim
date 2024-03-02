#ifndef CONFIG_IO_H
#define CONFIG_IO_H

#include <map>
#include <vector>
#include <memory>
#include <string>

/*
Usage:
    #include "config_io.h"
    using hivelab_config_io::Config;
    Config::SetConfigPath("/mypath/config.ini");
    // Or: Config::UseDefaultPath("config.ini");
    float my_var = Config::Get<float>("FieldName", "VarName");

    Included types: short int, int, long, long long, unsigned short, unsigned int, unsigned long, unsigned long long,
                    float, double, bool, vector in 1 or 2 dims.
*/

namespace hivelab_config_io
{
struct ConfigMetaData
{
public:
    std::string data_;

    ConfigMetaData() {}
    ConfigMetaData(std::string _data) : data_(_data) {}

    operator short() const { return (short int)strtol(data_.c_str(), NULL, 0); } // Overload of some common operators.

    operator int() const { return (int)strtol(data_.c_str(), NULL, 0); }

    operator long int() const { return strtol(data_.c_str(), NULL, 0); }

    operator long long() const { return strtoll(data_.c_str(), NULL, 0); }

    operator unsigned short() const { return (unsigned short)strtoul(data_.c_str(), NULL, 0); }

    operator unsigned int() const { return (unsigned int)strtoul(data_.c_str(), NULL, 0); }

    operator unsigned long int() const { return strtoul(data_.c_str(), NULL, 0); }

    operator unsigned long long() const { return strtoull(data_.c_str(), NULL, 0); }

    operator float() const { return atof(data_.c_str()); }

    operator double() const { return atof(data_.c_str()); }

    operator std::string() const { return data_; }

    operator bool() const { return bool(strtol(data_.c_str(), NULL, 0)); }
};

class Config
{
private:
    typedef std::map<std::string, ConfigMetaData> ConfigField;

    Config();

    /**
     * @brief TrimSpacingComment
     * 
     * @param _str 
     */
    void TrimSpacingComment(std::string &_str);

    /**
     * @brief PrintInfo
     * 
     * @param _str 
     */
    void PrintInfo(std::string _str);

    /**
     * @brief PrintErrInfo
     * 
     * @param _str 
     */
    void PrintErrInfo(std::string _str);

    /**
     * @brief PrintWarnInfo
     * 
     * @param _str 
     */
    void PrintWarnInfo(std::string _str);

    /**
     * @brief ReadConfigFile
     * 
     * @return true 
     * @return false 
     */
    static bool ReadConfigFile();

    /**
     * @brief ParseTrimLine
     * 
     * @param _file_line 
     * @param _file 
     * @return int 
     */
    static int ParseTrimLine(std::string &_file_line, std::fstream &_file);

    /**
     * @brief RecordConfigLine
     * 
     * @param _line 
     * @param _field 
     */
    static void RecordConfigLine(const std::string &_line, ConfigField &_field);

private:
    int kMaxFileLen = 1000;
    std::string kSeperator_;
    std::fstream *file_;
    std::map<std::string, ConfigField> config_strs_;
    static std::shared_ptr<Config> ptr_;

public:
    ~Config();

    /**
     * @brief Set the Config Path
     * 
     * @param _file_name 
     * @param _seperator 
     * @param _max_file_len 
     * @return true 
     * @return false 
     */
    static bool SetConfigPath(const std::string &_file_name, std::string _seperator = "=", int _max_file_len = 1000);

    /**
     * @brief use default path
     * 
     * @param _file_name 
     */
    static void UseDefaultPath(std::string _file_name);

    /**
     * @brief get value
     * 
     * @tparam T 
     * @param _field 
     * @param _var 
     * @return T 
     */
    template <typename T>
    static T Get(const std::string &_field, const std::string &_var)
    {
        if (ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())
            if (ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
                return T(ptr_->config_strs_[_field][_var]);

        ptr_->PrintErrInfo("Field name " + _field + " or variable name " + _var + " does not exist!");
        return 0;
    }

    /**
     * @brief Get the Vector object
     * 
     * @tparam T 
     * @param _field 
     * @param _var 
     * @return std::vector<T> 
     */
    template <typename T>
    static std::vector<T> GetVector(const std::string &_field, const std::string &_var)
    {
        std::vector<T> tmp_vector;
        tmp_vector.push_back(T(ConfigMetaData("0")));

        if (ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())
            if (ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
            {
                std::string tmp_str = ptr_->config_strs_[_field][_var].data_;

                if (tmp_str.find("{") != 0 || tmp_str.find("}") != tmp_str.size() - 1)
                {
                    ptr_->PrintErrInfo("Invalid data for vector type!");
                    return tmp_vector;
                }

                tmp_str.erase(0, 1); // Erase "{}" from the string.
                tmp_str.erase(tmp_str.find("}"), 1);
                if (tmp_str.rfind(",") == tmp_str.size() - 1) // Comma should not be the last letter.
                {
                    ptr_->PrintErrInfo("Invalid data for vector type!");
                    return tmp_vector;
                }

                if (tmp_str.rfind(";") != tmp_str.size() - 1) // Add ";" as the last letter.
                    tmp_str += ";";

                while (tmp_str.find(";") != std::string::npos) // Replace ";" with ",".
                    tmp_str.replace(tmp_str.find(";"), 1, ",");

                tmp_vector.clear();
                while (tmp_str.find(",") != std::string::npos) // Parse data iteratively.
                {
                    tmp_vector.push_back(T(ConfigMetaData(tmp_str.substr(0, tmp_str.find(",")))));
                    tmp_str.erase(0, tmp_str.find(",") + 1);
                }

                return tmp_vector;
            }

        ptr_->PrintErrInfo("Field name " + _field + " or variable name " + _var + " does not exist!");
        return tmp_vector;
    }

    /**
     * @brief Get the Vector 2 object
     * 
     * @tparam T 
     * @param _field 
     * @param _var 
     * @return std::vector<std::vector<T>> 
     */
    template <typename T>
    static std::vector<std::vector<T>> GetVector2(const std::string &_field, const std::string &_var)
    {
        std::vector<T> tmp_vector;
        std::vector<std::vector<T>> tmp_vector2;
        tmp_vector.push_back(T(ConfigMetaData("0")));
        tmp_vector2.push_back(tmp_vector);

        if (ptr_->config_strs_.find(_field) != ptr_->config_strs_.end())
            if (ptr_->config_strs_[_field].find(_var) != ptr_->config_strs_[_field].end())
            {
                std::string tmp_str = ptr_->config_strs_[_field][_var].data_;

                if (tmp_str.find("{") != 0 || tmp_str.find("}") != tmp_str.size() - 1)
                {
                    ptr_->PrintErrInfo("Invalid data for vector type!");
                    return tmp_vector2;
                }

                tmp_str.erase(0, 1);
                tmp_str.erase(tmp_str.find("}"), 1);
                if (tmp_str.rfind(",") == tmp_str.size() - 1)
                {
                    ptr_->PrintErrInfo("Invalid data for vector type!");
                    return tmp_vector2;
                }

                if (tmp_str.rfind(";") != tmp_str.size() - 1)
                    tmp_str += ";";

                tmp_vector2.clear();
                while (tmp_str.find(";") != std::string::npos)
                {
                    tmp_vector.clear();
                    std::string tmp_str_line = tmp_str.substr(0, tmp_str.find(";")) + ",";
                    tmp_str.erase(0, tmp_str.find(";") + 1);

                    while (tmp_str_line.find(",") != std::string::npos)
                    {
                        tmp_vector.push_back(T(ConfigMetaData(tmp_str_line.substr(0, tmp_str_line.find(",")))));
                        tmp_str_line.erase(0, tmp_str_line.find(",") + 1);
                    }
                    tmp_vector2.push_back(tmp_vector);
                }
                return tmp_vector2;
            }

        ptr_->PrintErrInfo("Field name " + _field + " or variable name " + _var + " does not exist!");
        return tmp_vector2;
    }

}; // class Config

} // namespace hivelab_config_io

#endif
