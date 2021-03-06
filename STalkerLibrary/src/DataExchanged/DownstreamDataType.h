#pragma once

#include <memory>
#include <vector>

#include <boost/property_tree/ptree.hpp>


namespace Interface{

/// Translates data from JSON frames (ROS) format on the input (ST) binary format
class DownstreamDataType
{
private:
protected:

    int stIdentifier;
    std::string potocolIndentificator;

public:

    virtual ~DownstreamDataType(){}
    std::string getProtocolIdentificator() const{ return potocolIndentificator;}
    virtual std::vector<uint8_t> serialize() = 0;
    virtual void deserialize(boost::property_tree::ptree& pt) = 0;
    virtual void doTheProcessing() = 0;

};

} //namespace STInterface
