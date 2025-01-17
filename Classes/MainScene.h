/*********************************************
Author: Zhang Hao
GitHub: https://github.com/120910383/mota
*********************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "player.h"

//class tiles_res;
struct tile_t;
struct floor_t;
struct pos_t;

namespace cocostudio { class Armature; }

class MainScene : public cocos2d::Layer, public player_delegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

    virtual void update(float delta) override;

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *e);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *e);

protected:
    void add_tile_sprite(const tile_t& tile);
    virtual void on_walk_turn(const pos_t& next) override;
    virtual void on_walk_stop() override;
    virtual void on_stair_change() override;
    virtual void on_pick_up_item() override;
    virtual void on_battle() override;

protected:
    const floor_t* _floor;
    cocos2d::Node* _map_node;
    cocos2d::Node* _arrow_node;
    cocostudio::Armature* _warrior_node;
};

#endif // __HELLOWORLD_SCENE_H__
