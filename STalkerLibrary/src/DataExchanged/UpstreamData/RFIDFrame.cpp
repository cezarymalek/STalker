#include "RFIDFrame.h"

#include <ros/console.h>

Interface::UpstreamData::RFIDFrame::RFIDFrame()
{
    protocolIndentificator = uint8_t{0x0E};
    datasetBinarySize = 5;
    rosTopic = "RFIDFrame";
}

Interface::UpstreamData::RFIDFrame::~RFIDFrame()
{

}

void Interface::UpstreamData::RFIDFrame::sendData(ROSInterface::ROSInterfaceClient &ROSClient)
{

    std_msgs::UInt32 data;

    data.data = cardID;

    ROSClient.publishUInt32(data, rosTopic);
}

void Interface::UpstreamData::RFIDFrame::deserialize(const char *iDataStream, const int iDataSize)
{
    if(iDataSize != datasetBinarySize)
    {
        ROS_ERROR("Bad Time Sync frame received. Length is mismatching");
        return;
    }
    cardID = iDataStream[0]<<24 | iDataStream[1]<<16 | iDataStream[2]<<8 | iDataStream[3];
}

std::string Interface::UpstreamData::RFIDFrame::serialize()
{

}

void Interface::UpstreamData::RFIDFrame::doTheProcessing()
{

}

std::unique_ptr<Interface::UpstreamDataType> Interface::UpstreamData::RFIDFrame::getClone()
{
    std::unique_ptr<Interface::UpstreamData::RFIDFrame>frame(new Interface::UpstreamData::RFIDFrame);

    frame->protocolIndentificator = protocolIndentificator;
    frame->datasetBinarySize = datasetBinarySize;
    frame->rosTopic = rosTopic;

    return std::move(frame);

}
