#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "../UpstreamDataType.h"

namespace Interface
{

namespace UpstreamData
{
class MovementInformationLeftRightFrame : public Interface::UpstreamDataType
{
private:

    int rightTurnDirection;
    int leftTurnDirection;

    int rightTurnValue;
    int leftTurnValue;
    int remainedTimeToDrive;

public:

    MovementInformationLeftRightFrame();
    virtual ~MovementInformationLeftRightFrame();

    void deserialize(std::vector<uint8_t> iDataStream) override;
    std::string  serialize() override;
    void doTheProcessing() override;
    std::unique_ptr<Interface::UpstreamDataType> getClone();

};
}
}

