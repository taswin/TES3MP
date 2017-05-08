//
// Created by koncord on 04.11.16.
//

#ifndef OPENMW_PACKETCONSOLE_HPP
#define OPENMW_PACKETCONSOLE_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

namespace mwmp
{
    class PacketConsole: public PlayerPacket
    {
    public:
        PacketConsole(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
        {
            packetID = ID_GAME_CONSOLE;
            orderChannel = CHANNEL_SYSTEM;
        }
        void Packet(RakNet::BitStream *bs, bool send)
        {
            PlayerPacket::Packet(bs, send);
            RW(player->consoleAllowed, send);
        }
    };
}


#endif //OPENMW_PACKETCONSOLE_HPP
