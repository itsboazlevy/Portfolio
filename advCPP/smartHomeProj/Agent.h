#ifndef AGENT_H
#define AGENT_H

#include <string>
#include "Event.h"

class Agent
{
public:
	Agent (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor);
	const std::string& GetId() const;
	const std::string& GetType() const;
	const std::string& GetLogName() const;
	const std::string& GetConfig() const;
	size_t GetRoom() const;
	size_t GetFloor() const;
	virtual ~Agent() = 0;
private:
	std::string m_id;
	std::string m_type;
	std::string m_logName;
	std::string m_config;
	size_t m_room;
	size_t m_floor;
};

#endif //AGENT_H
