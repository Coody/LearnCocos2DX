//
//  ClockPointTool.h
//  Test01
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef ClockPointTool_h
#define ClockPointTool_h

#include <stdio.h>
#include "cocos2d.h"

class ClockPointTool{

public:
    
    ClockPointTool();
    
    cocos2d::CCPoint getPoint(float radius , unsigned int hours , unsigned int mins );
    
private:
    
    
    
};

#endif /* ClockPointTool_hpp */
