// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2010 Daniel Krieg
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#ifndef _YARP2_AUTHHMAC_
#define _YARP2_AUTHHMAC_

#include <yarp/os/impl/InputStream.h>
#include <yarp/os/impl/OutputStream.h>

#include <hmac/hmac_sha2.h>

#define DIGEST_SIZE SHA256_DIGEST_SIZE
#define HMAC_CONTEXT hmac_sha256_ctx
#define HMAC_INIT hmac_sha256_init
#define HMAC_REINIT hmac_sha256_reinit
#define HMAC_UPDATE hmac_sha256_update
#define HMAC_FINAL hmac_sha256_final
#define NONCE_LEN 8

namespace yarp {
    namespace os {
        namespace impl {
            class AuthHMAC;
        }
    }
}

/**
 * 3-way authentication via HMAC
 */
class yarp::os::impl::AuthHMAC {
public:
    /**
     * Constructor.
     */
    AuthHMAC();

    /**
     * Destructor.
     */
    virtual ~AuthHMAC() {}

    bool authSource(yarp::os::impl::InputStream *streamIn, yarp::os::impl::OutputStream *streamOut);
    bool authDest(yarp::os::impl::InputStream *streamIn, yarp::os::impl::OutputStream *streamOut);

private:

    bool send_hmac(yarp::os::impl::OutputStream * stream, unsigned char* nonce, unsigned char* mac);
    bool receive_hmac(yarp::os::impl::InputStream * stream, unsigned char * nonce, unsigned char * mac);
    bool check_hmac(unsigned char * mac, unsigned char * mac_check);
    void fill_nonce(unsigned char* nonce);

    HMAC_CONTEXT context;
};

#endif
