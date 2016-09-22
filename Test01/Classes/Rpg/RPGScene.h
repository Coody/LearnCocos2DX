//
//  RPGScene.hpp
//  Test01
//
//  Created by Coody on 2016/9/21.
//
//

#ifndef RPGScene_h
#define RPGScene_h

#include "cocos2d.h"

// for Constant
#include "NpcConstant.h"

class RPGLayer : public cocos2d::CCLayerColor
{
public:
    
    virtual bool init();
    
    static cocos2d::CCScene *scene();
    
    static RPGLayer *create()
    {
        RPGLayer *pRet = new RPGLayer();
        if ( pRet && pRet->init() ) 
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
private:
    
    cocos2d::CCArray *npcArray;
    
    // 建立一個隨機 npc （會自動找個點行走）
    void createNpc();
    
    // 隨機命令一個 npc 移動
    void controlNpcMove();
    
    // 給一個隨機的點
    cocos2d::CCPoint getRandomPoint();
    
    // 取得圖片真正名稱
    const char *getImageName( EnumNpcName enumNpcName );
    
};

#endif /* RPGScene_hpp */
