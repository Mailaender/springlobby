/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


//
// Class: Server
//
// Created on: Fri Apr 27 16:23:28 2007
//

#include <assert.h>
#include "server.h"
#include "socket.h"

Server::Server()
{
  m_sock = NULL;
  m_ui = NULL;
  m_keepalive = 15;
}


Server::~Server()
{
}

void Server::set_socket( Socket* sock )
{
  assert( !is_connected() ); // Should disconnect first.
  m_sock = sock;
}

Socket* Server::get_socket( )
{
  return m_sock;
}


void Server::set_uicontrol( ServerEvents* ui )
{
  m_ui = ui;
}


ServerEvents* Server::get_uicontrol( )
{
  return m_ui;
}

void Server::set_username( const string username )
{
  m_user = username;
}


void Server::set_password( const string password )
{
  m_pass = password;
}

