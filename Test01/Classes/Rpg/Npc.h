//
//  Npc.h
//  Test01
//
//  Created by Coody on 2016/9/21.
//
//

#ifndef Npc_h
#define Npc_h

#include "cocos2d.h"

class Npc : public cocos2d::CCNode
{
public:
    
    // 設定 cache name ( *.png , *.plist )
    virtual bool init( const char *cachePlistName , const char *cacheImageName );
    
    static Npc *create( const char *cachePlistName , const char *cacheImageName )
    {
        Npc *pRet = new Npc();
        if ( pRet && pRet->init( cachePlistName , cacheImageName ) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void goToPoint( cocos2d::CCPoint tempPoint );
    
    cocos2d::CCString *npcName;
    
private:
    
    // 設定 animation cache
    void setNpcImageCacheName( const char *cachePlistName , const char *cacheImageName );
    
    // 往上走
    void goUp();
    // 往下走
    void goDown();
    // 往左走
    void goLeft();
    //往右走
    void goRight();
    // 設定 X & Y 方向為 0
    void setMovePointXZero();
    void setMovePointYZero();
    // 停止動畫
    void stopAnimation();
    
    // 記錄目前是否在動畫中
    bool m_bIsArriveTarget;
    
    // 記錄要走的路徑
    cocos2d::CCPoint movePoint;
    
    // image & plist
    cocos2d::CCString *m_sPlistString;
    cocos2d::CCString *m_sImageString;
    
    cocos2d::CCAnimation *m_upAnimation;
    cocos2d::CCAnimation *m_leftAnimation;
    cocos2d::CCAnimation *m_rightAnimation;
    cocos2d::CCAnimation *m_downAnimation;
    
};

#endif /* Npc_hpp */
