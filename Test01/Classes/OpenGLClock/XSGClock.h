//
//  XSGClock.h
//  Test01
//
//  Created by Coody on 2016/9/29.
//
//

#ifndef XSGClock_h
#define XSGClock_h

#include "cocos2d.h"

class XSGClock : public cocos2d::CCNode{
public:
    
    virtual bool init();
    CREATE_FUNC(XSGClock);
    
    void draw();
};

#endif /* XSGClock_hpp */
