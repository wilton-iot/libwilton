/* 
 * File:   SslConfig.hpp
 * Author: alex
 *
 * Created on June 13, 2016, 11:35 AM
 */

#ifndef WILTON_SERVERCONF_SSLCONFIG_HPP
#define	WILTON_SERVERCONF_SSLCONFIG_HPP

#include <string>

#include "staticlib/serialization.hpp"

#include "common/WiltonInternalException.hpp"
#include "common/utils.hpp"

namespace wilton {
namespace serverconf {

class SslConfig {
public:
    std::string keyFile = "";
    std::string keyPassword = "";
    std::string verifyFile = "";
    std::string verifySubjectSubstr = "";

    SslConfig(const SslConfig&) = delete;

    SslConfig& operator=(const SslConfig&) = delete;

    SslConfig(SslConfig&& other) :
    keyFile(std::move(other.keyFile)),
    keyPassword(std::move(other.keyPassword)),
    verifyFile(std::move(other.verifyFile)),
    verifySubjectSubstr(std::move(other.verifySubjectSubstr)) { }

    SslConfig& operator=(SslConfig&& other) {
        this->keyFile = std::move(other.keyFile);
        this->keyPassword = std::move(other.keyPassword);
        this->verifyFile = std::move(other.verifyFile);
        this->verifySubjectSubstr = std::move(other.verifySubjectSubstr);
        return *this;
    }
    
    SslConfig() { }
    
    SslConfig(const staticlib::serialization::json_value& json) {
        namespace ss = staticlib::serialization;
        for (const ss::json_field& fi : json.as_object()) {
            auto& name = fi.name();
            if ("keyFile" == name) {
                this->keyFile = common::get_json_string(fi);
            } else if ("keyPassword" == name) {
                // empty string allowed
                this->keyPassword = fi.as_string();
            } else if ("verifyFile" == name) {
                this->verifyFile = common::get_json_string(fi);
            } else if ("verifySubjectSubstr" == name) {
                this->verifySubjectSubstr = common::get_json_string(fi);
            } else {
                throw common::WiltonInternalException(TRACEMSG("Unknown 'ssl' field: [" + name + "]"));                
            }
        }
    }
    
    staticlib::serialization::json_value to_json() const {
        return {
            { "keyFile", keyFile },
            { "keyPassword", keyPassword},
            { "verifyFile", verifyFile},
            { "verifySubjectSubstr", verifySubjectSubstr}
        };
    }
    
    bool is_empty() const {
        return keyFile.empty();
    }
    
};

} // namespace
}

#endif	/* WILTON_SERVERCONF_SSLCONFIG_HPP */

