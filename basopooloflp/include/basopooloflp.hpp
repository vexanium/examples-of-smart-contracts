#pragma once
#include <math.h>
#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/transaction.hpp>
#include <eosiolib/crypto.hpp>
#include "eosio.token.hpp"


#define SWAPADMIN "basopooloflp" //"basopooloflp" //"testpooloflp"
#define VEXTOKEN "vex.token"
#define BASOTOKEN "vexbasotoken" //vexbasotoken testbastoken

#define SWAPLOG "vexswapoflog" 
#define SECONDS_PER_DAY  86400

#define POOLDRAW "basopooldraw"  //basopooldraw tstpoolsdraw 

#define VEX_SYMBOL eosio::symbol("VEX", 4)
#define BASO_SYMBOL eosio::symbol("BASO", 10)

#define ONCE_DEAL_NUM  50
//1k lp挖矿
#define STAGE_MINING_TOTAL eosio::asset(10000000000000, BASO_SYMBOL)


using eosio::extended_asset;
using namespace eosio;
using namespace std;

static constexpr int64_t max_amount  = 10000000000000000;

namespace vexbaso {
    class [[eosio::contract]] basopooloflp :public eosio::contract {
    public:
        basopooloflp(eosio::name receiver, eosio::name code, eosio::datastream<const char *> ds) :
                eosio::contract(receiver, code, ds),
                _global(eosio::name(SWAPADMIN), eosio::name(SWAPADMIN).value),
                _lppools(eosio::name(SWAPADMIN), eosio::name(SWAPADMIN).value),
                _userbonus(eosio::name(SWAPADMIN), eosio::name(SWAPADMIN).value){
                     eosio::token eos_token = eosio::token(name(SWAPADMIN),code,ds);
                     ptoken = &eos_token;
        }

        ACTION initmpool(const uint32_t &epoch); 

        ACTION setmpreward(const eosio::asset &reward); 

        ACTION mdflppool(const uint64_t &pool_id, const uint16_t &weight, const double &APY);

        ACTION removelppool(const uint64_t &pool_id);

        ACTION setlppool(const uint64_t &mid, const uint8_t &state, const uint16_t &weight, const string &title, const string &desc,
                 const uint8_t &icon, const uint64_t &total_staked, const uint64_t &pool_total, const  double &APY, const string &poolContract, const string &poolCode);

        ACTION updatelppool(const uint64_t &mid, const uint64_t &pool_total, const  double &APY);

        ACTION claim(const eosio::name &from, const uint64_t &pool_id);
        
        // ACTION swapming(const eosio::name &user, const eosio::extended_asset &swapvex);

        ACTION harvest(const uint64_t &pool_id, const uint32_t &liq_id);
        
        // ACTION init(); 

        ACTION setstop(const uint8_t &state);

        bool isvextoken(const eosio::extended_asset &quantity)
        {
            //print("quantity.contract", quantity.contract); 
            if ((quantity.contract == eosio::name(VEXTOKEN)) && (quantity.quantity.symbol == VEX_SYMBOL))
            {
                return true;
            }
            return false;
        }

        void apply(eosio::name code, eosio::name action);

        void onTransfer(const eosio::name &from,
            const eosio::name &to,
            const eosio::extended_asset &quantity,
            const string &memo);

        TABLE minepool {
            uint64_t id;
            uint64_t maxpoolid;
            uint8_t stopState;
            // uint8_t swapMingState;
            // double swapMingfactor;
            uint32_t total_weight = 0;
            uint32_t epoch = 0;

            eosio::asset all_pool_reward = asset(0, BASO_SYMBOL);

            eosio::asset basousdvlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basovexlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset vexusdvlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset vynvexlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset vynusdvlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basovynlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basobatiklp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basodjvlp_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basobnkri_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset djvvexlp_day_reward = asset(0, BASO_SYMBOL);

            eosio::asset basordng_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basosate_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basotrafi_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basoecash_day_reward = asset(0, BASO_SYMBOL);
            eosio::asset basoad_day_reward = asset(0, BASO_SYMBOL);

            eosio::asset total_mined = asset(0, BASO_SYMBOL);

            uint64_t last_harvest_poolid;
            uint64_t last_harvest_liqid;
            uint32_t last_harvest_time;
            uint8_t once_harvest_num;
        };
        typedef eosio::singleton<"minepool"_n, minepool> minepool_table;

        //"state": 1, 即将开始 "state": 2, 进行中 "state": 3,已结束
        //只用来展示pools 信息 
        TABLE lpmappool {
            uint64_t mid;
            uint64_t poolid;
            uint8_t state;
            uint16_t weight = 0;
            string title = "";
            string desc = "";
            uint8_t icon;
            uint64_t total_staked;
            uint64_t pool_total;
            double APY;
            string poolContract = "";
            string scope = "";
            uint64_t by_marketid() const { return mid; }
            int64_t primary_key() const { return poolid; }
        };
        typedef eosio::multi_index<"lpmappool"_n, lpmappool,
                        eosio::indexed_by<"marketid"_n, eosio::const_mem_fun<lpmappool, uint64_t, &lpmappool::by_marketid>>
                            > lpmappool_table;

        //scop id
        TABLE lpuser {
            eosio::name user;
            uint64_t staked = 0;
            eosio::asset claimed = asset(0, BASO_SYMBOL);
            eosio::asset unclaimed = asset(0, BASO_SYMBOL);

            uint64_t primary_key() const { return user.value; }
        };
        typedef eosio::multi_index<"lpuser"_n, lpuser> lpuser_table;


        TABLE userbonus {
            eosio::name user;
            eosio::asset claimed = asset(0, BASO_SYMBOL);
            eosio::asset unclaimed = asset(0, BASO_SYMBOL);

            uint64_t primary_key() const { return user.value; }
        };
        typedef eosio::multi_index<"userbonus"_n, userbonus> userbonus_table;


        eosio::token *ptoken;

        minepool_table _global;
        lpmappool_table _lppools;
        userbonus_table _userbonus;

        ACTION test()
        {
            require_auth(eosio::name(SWAPADMIN));

            auto itr = _lppools.begin();
            while(itr != _lppools.end()){
                itr = _lppools.erase(itr);
            }

            _global.remove( );

            // auto global = _global.get_or_default();
            // global.id = 1;
            // global.maxpoolid = 8;
            // global.stopState = 0;
            // global.total_weight = 100;
            // global.epoch = 1618545600;
            // global.all_pool_reward = asset(10000000000, BASO_SYMBOL);
            // global.basousdvlp_day_reward = asset(583333333333, BASO_SYMBOL);
            // global.basovexlp_day_reward = asset(499999999999, BASO_SYMBOL);
            // global.vexusdvlp_day_reward = asset(249999999999, BASO_SYMBOL);
            // global.vynvexlp_day_reward = asset(83333333333, BASO_SYMBOL);
            // global.vynusdvlp_day_reward = asset(83333333333, BASO_SYMBOL);
            // global.basovynlp_day_reward = asset(49999999999, BASO_SYMBOL);
            // global.basobatiklp_day_reward = asset(49999999999, BASO_SYMBOL);
            // global.basodjvlp_day_reward = asset(33333333333, BASO_SYMBOL);
            // global.djvvexlp_day_reward = asset(33333333333, BASO_SYMBOL);
            // global.total_mined = asset(92208421536301, BASO_SYMBOL);
            // global.last_harvest_poolid = 0;
            // global.last_harvest_liqid = 0;
            // global.last_harvest_time = 1623918422;
            // global.once_harvest_num = 50;
            // _global.set(global, eosio::name(SWAPADMIN));

            // auto itr = _lppools.begin();
            // while(itr != _lppools.end()){
            //     lpuser_table lpusers(name(SWAPADMIN), itr->poolid);
            //     auto itr2 = lpusers.begin();
            //     while(itr2 != lpusers.end()){
            //         itr2 = lpusers.erase(itr2);
            //     }
            //     itr = _lppools.erase(itr);
            // }
            //清空未提取，重新统计已挖矿
            // auto global = _global.get_or_default();
            //  global.total_mined = asset(0, BASO_SYMBOL);
            // _global.set(global, eosio::name(SWAPADMIN));

            // auto itr3 = _userbonus.begin();
            // while(itr3 != _userbonus.end()){
            //     itr3 = _userbonus.erase(itr3);
            // }
            // //eosio::asset totalunclaimed = asset(0, BASO_SYMBOL);
            // eosio::asset totalclaimed = asset(0, BASO_SYMBOL);
            // auto itr = _lppools.begin();
            // while(itr != _lppools.end()){
            //     lpuser_table lpusers(name(SWAPADMIN), itr->poolid);
            //     auto itr2 = lpusers.begin();
            //     while(itr2 != lpusers.end()){
            //         // if(itr2->unclaimed.amount > 0)
            //         // {
            //         //     totalunclaimed += itr2->unclaimed;
            //         // }
            //         //清空所有未领取
            //         if(itr2->claimed.amount > 0)
            //         {
            //             totalclaimed += itr2->claimed;

            //             //判断是否已存在
            //             auto itruserbonus = _userbonus.find(itr2->user.value);
            //             if (itruserbonus == _userbonus.end()) 
            //             {
            //                 _userbonus.emplace( name(SWAPADMIN), [&]( auto& u ) {
            //                     u.user = itr2->user;
            //                     u.claimed = itr2->claimed;
            //                     u.unclaimed = asset(0, BASO_SYMBOL);
            //                 });
            //             }
            //             else
            //             {
            //                 _userbonus.modify( itruserbonus, name(SWAPADMIN), [&]( auto& r) {          
            //                     r.claimed += itr2->claimed;
            //                 }); 
            //             }
            //         }

            //         auto itriduser = lpusers.find(itr2->user.value);
            //         lpusers.modify( itriduser, name(SWAPADMIN), [&]( auto& u ) {
            //             u.claimed = u.claimed.amount > 0 ? u.claimed : asset(0, BASO_SYMBOL);
            //             u.unclaimed = asset(0, BASO_SYMBOL);          
            //         });

                    
            //         itr2++;
            //     }
            //     itr++;
            // }

            // global.total_mined = totalclaimed;
            // _global.set(global, eosio::name(SWAPADMIN));
            // string error = " totalunclaimed: " + std::to_string(totalunclaimed.amount)  + " totalclaimed: " + std::to_string(totalclaimed.amount) ; 
            // eosio_assert(false, error.data());
        }
    };



    void basopooloflp::apply(eosio::name code, eosio::name action)
    {        
        if (code != eosio::name(SWAPADMIN))
            return;
        if( code == eosio::name(SWAPADMIN) ) {
            switch(action.value) {
                case eosio::name("test").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::test); 
                    break;
                case eosio::name("setstop").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::setstop); 
                    break;
                case eosio::name("initmpool").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::initmpool); 
                    break;
                case eosio::name("setmpreward").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::setmpreward); 
                    break;
                case eosio::name("mdflppool").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::mdflppool); 
                    break;
                case eosio::name("removelppool").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::removelppool); 
                    break;
                case eosio::name("setlppool").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::setlppool); 
                    break;
                case eosio::name("updatelppool").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::updatelppool); 
                    break;
                case eosio::name("claim").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::claim); 
                    break;
                case eosio::name("harvest").value: 
                    execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::harvest); 
                    break;
                // case eosio::name("swapming").value: 
                //     execute_action(eosio::name(SWAPADMIN), eosio::name(code), &basopooloflp::swapming); 
                //     break;
            }
        }
    }


    extern "C"
    {
        [[noreturn]] void apply(uint64_t receiver, uint64_t code, uint64_t action) {
            eosio::datastream<const char*> ds( nullptr, 0 );
            basopooloflp p(eosio::name(receiver), eosio::name(code), ds);
            p.apply(eosio::name(code), eosio::name(action));
            eosio_exit(0);
        }
    }

} /// namespace eosio
