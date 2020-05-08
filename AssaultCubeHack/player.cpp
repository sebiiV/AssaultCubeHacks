#include "player.h"


Player::Player(unsigned int ID,HANDLE hProcess,uintptr_t p_entity) {
	this->playerID = ID;
	this->hProcess = hProcess;
	this->p_entity = p_entity;
}


std::string Player::getName() {
	std::vector<unsigned int> offsets = {playerID, name_offset };
	uintptr_t nameAddr = findVMAAddy(hProcess, p_entity, offsets);
	char buf[20];
	ReadProcessMemory(hProcess, (BYTE*)nameAddr, &buf, sizeof(buf), nullptr);
	buf[19] = '\0'; //very dirty hack to ensure its null terminated
	this->name = std::string(buf);
	return name;
}

Vector3 Player::getHeadPos() {
	std::vector<unsigned int> offsets = {playerID, headPos_offset };
	uintptr_t posAddr = findVMAAddy(hProcess, p_entity, offsets);
	ReadProcessMemory(hProcess, (BYTE*)posAddr, &headPos, sizeof(headPos), nullptr);
	return headPos;
}

Vector3 Player::getFootPos() {
	std::vector<unsigned int> offsets = {playerID, footPos_offset };
	uintptr_t posAddr = findVMAAddy(hProcess, p_entity, offsets);
	ReadProcessMemory(hProcess, (BYTE*)posAddr, &footPos, sizeof(footPos), nullptr);
	return footPos;
}

void Player::setPitch(float pitch) {
	std::vector<unsigned int> offsets = {playerID, pitch_offset };
	uintptr_t pitchAddr = findVMAAddy(hProcess, p_entity, offsets);
	WriteProcessMemory(hProcess, (BYTE*)pitchAddr, &pitch, sizeof(pitch), nullptr);

}

void Player::setYaw(float yaw) {
	std::vector<unsigned int> offsets = {playerID, yaw_offset };
	uintptr_t yawAddr = findVMAAddy(hProcess, p_entity, offsets);
	WriteProcessMemory(hProcess, (BYTE*)yawAddr, &yaw, sizeof(yaw), nullptr);

}
