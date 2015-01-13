/**
 *
 * Based on simple_broadcast_server-example of websocketpp:
 * https://github.com/zaphoyd/websocketpp/tree/master/examples/simple_broadcast_server
 *
 * @author Michael Zapf <michael.zapf@fau.de>
 * @file
 */

#ifndef WS_SERVER_H
#define WS_SERVER_H

//#include "nrf_server.h"

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;
using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

//class nrf_server;

class ws_server {
    public:
        ws_server() {
            // Set logging settings
            m_server.set_access_channels(websocketpp::log::alevel::all);
            m_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

            m_server.init_asio();
            m_server.set_open_handler(bind(&ws_server::on_open,this,::_1));
            m_server.set_close_handler(bind(&ws_server::on_close,this,::_1));
            m_server.set_message_handler(bind(&ws_server::on_message,this,::_1,::_2));
        }
        void on_open(connection_hdl hdl) {
            m_connections.insert(hdl);
        }
        void on_close(connection_hdl hdl) {
            m_connections.erase(hdl);
        }
        void on_message(connection_hdl hdl, server::message_ptr msg) {
            // TODO: JSON-Objekt auspacken und cowpacket versenden

            //to_nrfs->send_json(msg->get_payload());
        }
        void send(std::string const & msg) {
            for (auto it : m_connections) {
                m_server.send(it, msg, websocketpp::frame::opcode::TEXT);
            }
        }
        void run(uint16_t port) {
            m_server.listen(port);
            m_server.start_accept();
            m_server.run();
        }

        /**
         * TODO
         */
        //void set_to_nrfs(nrf_server* callback) {
        //    to_nrfs = callback;
        //}

    private:
        typedef std::set<connection_hdl,std::owner_less<connection_hdl>> con_list;
        server          m_server;
        con_list        m_connections;
        //nrf_server*     to_nrfs;
};



#endif  // WS_SERVER_H
