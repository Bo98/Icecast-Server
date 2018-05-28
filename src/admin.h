/* Icecast
 *
 * This program is distributed under the GNU General Public License, version 2.
 * A copy of this license is included with this source.
 *
 * Copyright 2000-2004, Jack Moffitt <jack@xiph.org,
 *                      Michael Smith <msmith@xiph.org>,
 *                      oddsock <oddsock@xiph.org>,
 *                      Karl Heyes <karl@xiph.org>
 *                      and others (see AUTHORS for details).
 * Copyright 2011-2018, Philipp "ph3-der-loewe" Schafft <lion@lion.leolix.org>,
 */

#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "refbuf.h"
#include "client.h"
#include "source.h"
#include "auth.h"

/* types */
#define ADMINTYPE_ERROR   (-1)
#define ADMINTYPE_GENERAL   1
#define ADMINTYPE_MOUNT     2
#define ADMINTYPE_HYBRID    (ADMINTYPE_GENERAL|ADMINTYPE_MOUNT)

/* formats */
#define RAW                 1
#define TRANSFORMED         2
#define PLAINTEXT           3

/* special commands */
#define ADMIN_COMMAND_ERROR (-1)
#define ADMIN_COMMAND_ANY   0 /* for ACL framework */

void admin_handle_request(client_t *client, const char *uri);

void admin_send_response(xmlDocPtr    doc,
                         client_t    *client,
                         int          response,
                         const char  *xslt_template);

void admin_add_listeners_to_mount(source_t       *source,
                                  xmlNodePtr      parent,
                                  operation_mode  mode);

xmlNodePtr admin_add_role_to_authentication(auth_t *auth, xmlNodePtr parent);

int admin_get_command(const char *command);
int admin_get_command_type(int command);

#endif  /* __ADMIN_H__ */
