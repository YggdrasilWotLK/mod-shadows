/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWCOMMANDSERVER_H
#define _SHADOW_SHADOWCOMMANDSERVER_H

class ShadowCommandServer
{
public:
    ShadowCommandServer() {}
    virtual ~ShadowCommandServer() {}
    static ShadowCommandServer* instance()
    {
        static ShadowCommandServer instance;
        return &instance;
    }

    void Start();
};

#define sShadowCommandServer ShadowCommandServer::instance()

#endif
