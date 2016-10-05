//
//  BlockGameConstant.h
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#ifndef BlockGameConstant_h
#define BlockGameConstant_h

#define D_Dev_Ver

#define D_BlockGame_ActionSpeed (1.0f)
#define D_BlockGame_BlockMoveSpeed (1.0f)
#define D_BlockGame_BackgroundColor cocos2d::ccc4(242, 242, 242, 255)
#define D_BlockGame_LevelLayerColor cocos2d::ccc4(56, 174, 82, 255)
#define D_BlockGame_FontName "From Cartoon Blocks"
#define D_BlockGame_FontName2 "Luckiest Guy"
#define D_Label_Image1 ""
#define D_Label_Image1_Width (0.0f)
#define D_Label_Image1_Height (0.0f)

#define D_BlockGame_BlockMaxCount (40)
#define D_BlockGame_GameBoardWidth (6)
#define D_BlockGame_GameBoardHeight (9)
#define D_BlockGame_GameBoardMax (D_BlockGame_GameBoardWidth*D_BlockGame_GameBoardHeight)
#define D_BlockGame_TimeMax (999)

#define D_BlockGame_SkillMax (15)
#define D_BlockGame_Skillmin (0)

typedef enum{
    EnumBasicBlockType_Normal = 1,
    EnumBasicBlockType_SkillLevelUp,
    EnumBasicBlockType_Super
}EnumBasicBlockType;

typedef enum{
    EnumGameBoard_Level_Easy = 1,
    EnumGameBoard_Level_Normal,
    EnumGameBoard_Level_Hard,
    EnumGameBoard_Level_Crazy
}EnumGameBoard_Level;

#endif /* BlockGameConstant_h */
