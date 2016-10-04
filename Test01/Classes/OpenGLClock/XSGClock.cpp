//
//  XSGClock.cpp
//  Test01
//
//  Created by Coody on 2016/9/29.
//
//

#include "XSGClock.h"

USING_NS_CC;

bool XSGClock::init(){
    
    if ( CCNode::init() ) {
        
        return true;
    }
    
    return false;
}


void XSGClock::draw(){
    
    // 圓
    glLineWidth(2);
    ccDrawColor4B(255, 255, 255, 255);
    ccDrawCircle( ccp(0, 0), 250, CC_RADIANS_TO_DEGREES(0), 100, false);
    
    // 
}
