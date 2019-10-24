#include "TimersFrame.h"

Interface::UpstreamData::TimersFrame::TimersFrame()
{
    protocolIndentificator = uint8_t{0x03};
    datasetBinarySize = 0;//Unknown yet therefore can't be implemented
}

Interface::UpstreamData::TimersFrame::~TimersFrame()
{

}

void Interface::UpstreamData::TimersFrame::deserialize(std::vector<uint8_t> iDataStream)
{

}

boost::property_tree::ptree Interface::UpstreamData::TimersFrame::serialize()
{

}

void Interface::UpstreamData::TimersFrame::doTheProcessing()
{

}

std::unique_ptr<Interface::UpstreamDataType> Interface::UpstreamData::TimersFrame::getClone()
{
    std::unique_ptr<Interface::UpstreamData::TimersFrame>timersFrame(new Interface::UpstreamData::TimersFrame);
    return std::move(timersFrame);
}
