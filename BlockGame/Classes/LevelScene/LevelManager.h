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
  
private:
    
    typedef enum{
        EnumLevelManagerTag_TitleLabel = 10,
        EnumLevelManagerTag_MenuHard = 20,
        EnumLevelManagerTag_MenuMid = 30,
        EnumLevelManagerTag_MenuEasy = 40,
        EnumLevelManagerTag_MenuCrazy = 50
    }EnumLevelManagerTag;
    
    void initialTitle();
    void initialMenu();
    void startLevelAnimation();
    void endLevelAnimation();
    
    void pressedHardLevel();
    void pressedMidLevel();
    void pressedLowLevel();
    
};

#endif /* LevelManager_h */
