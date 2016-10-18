//
//  LevelManager.hpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#ifndef LevelManager_h
#define LevelManager_h

#include "cocos2d.h"

class LevelManager final : public cocos2d::CCLayerColor{
public:
    LevelManager();
    virtual ~LevelManager();
    
    virtual bool init();
    
    CREATE_FUNC( LevelManager ) ;
    
};

#endif /* LevelManager_h */
