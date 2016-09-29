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
    
    // 設定移動到 point 的位置
    void goToPoint( cocos2d::CCPoint tempPoint );
    
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
    const char *m_sPlist;
    const char *m_sImage;
    cocos2d::CCString *m_sPlistString;
    cocos2d::CCString *m_sImageString;
    
};

#endif /* Npc_hpp */
