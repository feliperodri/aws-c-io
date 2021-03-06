/*
 * Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
#include <aws/io/io.h>

#define AWS_DEFINE_ERROR_INFO_IO(CODE, STR) AWS_DEFINE_ERROR_INFO(CODE, STR, "aws-c-io")

/* clang-format off */
static struct aws_error_info s_errors[] = {
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_CHANNEL_ERROR_ERROR_CANT_ACCEPT_INPUT,
        "Channel cannot accept input"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_CHANNEL_UNKNOWN_MESSAGE_TYPE,
        "Channel unknown message type"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_CHANNEL_READ_WOULD_EXCEED_WINDOW,
        "A channel handler attempted to propagate a read larger than the upstream window"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_EVENT_LOOP_ALREADY_ASSIGNED,
        "An attempt was made to assign an io handle to an event loop, but the handle was already assigned."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SYS_CALL_FAILURE,
        "System call failure"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_ERROR_NEGOTIATION_FAILURE,
        "TLS (SSL) negotiation failed"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_ERROR_NOT_NEGOTIATED,
        "Attempt to read/write, but TLS (SSL) hasn't been negotiated"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_ERROR_WRITE_FAILURE,
        "Failed to write to TLS handler"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_ERROR_ALERT_RECEIVED,
        "Fatal TLS Alert was received"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_CTX_ERROR,
        "Failed to create tls context"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_TLS_VERSION_UNSUPPORTED,
        "A TLS version was specified that is currently not supported. Consider using AWS_IO_TLS_VER_SYS_DEFAULTS, "
        " and when this lib or the operating system is updated, it will automatically be used."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_MISSING_ALPN_MESSAGE,
        "An ALPN message was expected but not received"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_UNHANDLED_ALPN_PROTOCOL_MESSAGE,
        "An ALPN message was received but a handler was not created by the user"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_FILE_INVALID_PATH,
        "Invalid file path."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_FILE_VALIDATION_FAILURE,
        "A file was read and the input did not match the expected value"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_ERROR_IO_EVENT_LOOP_THREAD_ONLY,
        "Attempt to perform operation that must be run inside the event loop thread"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_ERROR_IO_ALREADY_SUBSCRIBED,
        "Already subscribed to receive events"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_ERROR_IO_NOT_SUBSCRIBED,
        "Not subscribed to receive events"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_ERROR_IO_OPERATION_CANCELLED,
        "Operation cancelled before it could complete"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_READ_WOULD_BLOCK,
        "Read operation would block, try again later"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_BROKEN_PIPE,
        "Attempt to read or write to io handle that has already been closed."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_MAX_FDS_EXCEEDED,
        "The maximum number of fds has been exceeded."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_UNSUPPORTED_ADDRESS_FAMILY,
        "Socket, unsupported address family."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_NO_PERMISSION,
        "User does not have permission to perform the requested action."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_INVALID_OPERATION_FOR_TYPE,
        "Invalid socket operation for socket type."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_CONNECTION_REFUSED,
        "socket connection refused."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_TIMEOUT,
        "socket operation timed out."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_NO_ROUTE_TO_HOST,
        "socket connect failure, no route to host."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_NETWORK_DOWN,
        "network is down."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_CLOSED,
        "socket is closed."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_NOT_CONNECTED,
        "socket not connected."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_INVALID_OPTIONS,
        "Invalid socket options."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_ADDRESS_IN_USE,
        "Socket address already in use."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_INVALID_ADDRESS,
        "Invalid socket address."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_ILLEGAL_OPERATION_FOR_STATE,
        "Illegal operation for socket state."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_SOCKET_CONNECT_ABORTED,
        "Incoming connection was aborted."),
    AWS_DEFINE_ERROR_INFO_IO (
        AWS_IO_DNS_QUERY_FAILED,
        "A query to dns failed to resolve."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_DNS_INVALID_NAME,
        "Host name was invalid for dns resolution."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_DNS_NO_ADDRESS_FOR_HOST,
        "No address was found for the supplied host name."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_DNS_HOST_REMOVED_FROM_CACHE,
        "The entries for host name were removed from the local dns cache."),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_STREAM_INVALID_SEEK_POSITION,
        "The seek position was outside of a stream's bounds"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_STREAM_UNSEEKABLE,
        "Stream does not support seek operations"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_STREAM_READ_FAILED,
        "Stream failed to read from the underlying io source"),
    AWS_DEFINE_ERROR_INFO_IO(
        AWS_IO_INVALID_FILE_HANDLE,
        "Operation failed because the file handle was invalid"),
};
/* clang-format on */

static struct aws_error_info_list s_list = {
    .error_list = s_errors,
    .count = sizeof(s_errors) / sizeof(struct aws_error_info),
};

static bool s_error_strings_loaded = false;

void aws_io_load_error_strings(void) {
    if (!s_error_strings_loaded) {
        s_error_strings_loaded = true;
        aws_register_error_info(&s_list);
    }
}
