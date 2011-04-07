/*  =========================================================================
    zctx - working with 0MQ contexts

    -------------------------------------------------------------------------
    Copyright (c) 1991-2011 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of zapi, the C binding for 0MQ: http://zapi.zeromq.org.

    This is free software; you can redistribute it and/or modify it under the
    terms of the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your option)
    any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABIL-
    ITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __ZCTX_H_INCLUDED__
#define __ZCTX_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif


//  Opaque class structure
typedef struct _zctx_t zctx_t;

//  @interface
//  Create new context, returns context object, replaces zmq_init
zctx_t *
    zctx_new (void);

//  Destroy context and all sockets in it, replaces zmq_term
void
    zctx_destroy (zctx_t **self_p);

//  Create new shadow context, returns context object
zctx_t *
    zctx_shadow (zctx_t *self);

//  Raise default I/O threads from 1, for crazy heavy applications
void
    zctx_set_iothreads (zctx_t *self, int iothreads);

//  Set msecs to flush sockets when closing them
void
    zctx_set_linger (zctx_t *self, int linger);

//  Create socket within this context, replaces zmq_socket
void *
    zctx_socket_new (zctx_t *self, int type);

//  Destroy socket, replaces zmq_close
void
    zctx_socket_destroy (zctx_t *self, void *socket);

//  Self test of this class
int
    zctx_test (Bool verbose);

//  Global signal indicator, TRUE when user presses Ctrl-C or the process
//  gets a SIGTERM signal.
extern int zctx_interrupted;
//  @end

#ifdef __cplusplus
}
#endif

#endif
