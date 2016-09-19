//
//  MoveSpriteScene.h
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#ifndef MoveSpriteScene_h
#define MoveSpriteScene_h

#include "cocos2d.h"

class MoveSpriteLayer : cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    static MoveSpriteLayer *create(){
        MoveSpriteLayer *pRet = new MoveSpriteLayer();
        if ( pRet && pRet->init() ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
private:
    cocos2d::CCLabelTTF *titleLabel;
    cocos2d::CCMenu *createSpriteMenu;
    cocos2d::CCArray *spriteArray;
    
    void createSprite();
    
};

#endif /* MoveSpriteScene_h */
