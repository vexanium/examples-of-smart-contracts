#include "basopooloflp.hpp"


namespace vexbaso {

    void basopooloflp::initmpool(const uint32_t &epoch)
    {
        require_auth(eosio::name(SWAPADMIN));

        // BASO/USDV LP 200
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 97;
                u.poolid = 0;
                u.state = 2; 
                u.weight = 200;
                u.title = "BASO/USDV";
                u.desc = "BASO/USDV";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPCS";     
            });
        
         // BASO/VEX LP 200
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 95;
                u.poolid = 1;
                u.state = 2; 
                u.weight = 200;
                u.title = "BASO/VEX";
                u.desc = "BASO/VEX";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPCQ";     
            });
        // VEX/USDV LP 100
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 16;
                u.poolid = 2;
                u.state = 2; 
                u.weight = 100;
                u.title = "VEX/USDV";
                u.desc = "VEX/USDV";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPP";     
            });
        // VYN/VEX LP 100
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 0;
                u.poolid = 3;
                u.state = 2; 
                u.weight = 100;
                u.title = "VYN/VEX";
                u.desc = "VYN/VEX";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOP";     
            });
        // VYN/USDV LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 4;
                u.poolid = 4;
                u.state = 2; 
                u.weight = 50;
                u.title = "VYN/USDV";
                u.desc = "VYN/USDV";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPD";     
            });
        // BASO/VYN LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 94;
                u.poolid = 5;
                u.state = 2; 
                u.weight = 50;
                u.title = "BASO/VYN";
                u.desc = "BASO/VYN";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPCP";     
            });
        // BASO/BATIK 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 99;
                u.poolid = 6;
                u.state = 2; 
                u.weight = 50;
                u.title = "BASO/BATIK";
                u.desc = "BASO/BATIK";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPCU";     
            });
        // BASO/DJV LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 105;
                u.poolid = 7;
                u.state = 2; 
                u.weight = 50;
                u.title = "BASO/DJV";
                u.desc = "BASO/DJV";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPDA";     
            });
        // BASO/BNKRI LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 161;
                u.poolid = 8;
                u.state = 2; 
                u.weight = 50;
                u.title = "BASO/BNKRI";
                u.desc = "BASO/BNKRI";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPFE";     
            });
        // DJV/VEX LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 2;
                u.poolid = 9;
                u.state = 2; 
                u.weight = 50;
                u.title = "DJV/VEX";
                u.desc = "DJV/VEX";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPB";     
            });
        
        // BASO/RDNG LP 20
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 150;
                u.poolid = 10;
                u.state = 2; 
                u.weight = 20;
                u.title = "BASO/RDNG";
                u.desc = "BASO/RDNG";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPET";     
            });
        // BASO/SATE 20
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 185;
                u.poolid = 11;
                u.state = 2; 
                u.weight = 20;
                u.title = "BASO/SATE";
                u.desc = "BASO/SATE";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPGC";     
            });
        // BASO/TRAFI LP 20
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 125;
                u.poolid = 12;
                u.state = 2; 
                u.weight = 20;
                u.title = "BASO/TRAFI";
                u.desc = "BASO/TRAFI";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPDU";     
            });
        // BASO/ECASH LP 20
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 207;
                u.poolid = 13;
                u.state = 2; 
                u.weight = 20;
                u.title = "BASO/ECASH";
                u.desc = "BASO/ECASH";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPGY";     
            });
        // BASO/AD LP 50
        _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                u.mid = 214;
                u.poolid = 14;
                u.state = 2; 
                u.weight = 50;
                u.title = "BASO/AD";
                u.desc = "BASO/AD";
                u.icon = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 2;    
                u.poolContract = "vextokenswap"; 
                u.scope = "DOPHF";     
            });
        
        auto global = _global.get_or_default();
        global.id = 1;
        global.maxpoolid = 14;
        global.stopState = 0;
        global.total_weight = 1000;
        global.epoch = epoch;
        global.all_pool_reward = asset(1000000000, BASO_SYMBOL);
        //315s 0.1  1k 1year 

        eosio::asset day_reward = asset(274285714285, BASO_SYMBOL);
        global.basousdvlp_day_reward = day_reward * 200 /1000;
        global.basovexlp_day_reward = day_reward * 200 /1000;
        global.vexusdvlp_day_reward = day_reward * 100 /1000;
        global.vynvexlp_day_reward = day_reward * 100 /1000;
        global.vynusdvlp_day_reward = day_reward * 50 /1000;
        global.basovynlp_day_reward = day_reward * 50 /1000;
        global.basobatiklp_day_reward = day_reward * 50 /1000;
        global.basodjvlp_day_reward = day_reward * 50 /1000;
        global.basobnkri_day_reward = day_reward * 50 /1000;
        global.djvvexlp_day_reward = day_reward * 50 /1000;

        global.basordng_day_reward = day_reward * 20 /1000;
        global.basosate_day_reward = day_reward * 20 /1000;
        global.basotrafi_day_reward = day_reward * 20 /1000;
        global.basoecash_day_reward = day_reward * 20 /1000;
        global.basoad_day_reward = day_reward * 20 /1000;

        global.total_mined = asset(0, BASO_SYMBOL);

        global.last_harvest_poolid = 0;
        global.last_harvest_liqid = 0;
        global.last_harvest_time = epoch;
        global.once_harvest_num = ONCE_DEAL_NUM;
        _global.set(global, eosio::name(SWAPADMIN));
    }

    void basopooloflp::setmpreward(const eosio::asset &reward)
    {
        require_auth(eosio::name(SWAPADMIN));
        auto global = _global.get_or_default();

        eosio_assert(reward.symbol == BASO_SYMBOL, "wrong reward token!");

        global.all_pool_reward = reward;
        _global.set(global, eosio::name(SWAPADMIN));

    }

    void basopooloflp::mdflppool(const uint64_t &pool_id, const uint16_t &weight, const double &APY)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");

        require_auth(eosio::name(SWAPADMIN));

        auto itrpool = _lppools.find(pool_id);
        eosio_assert(itrpool != _lppools.end(), "lppool not exist!");

        _lppools.modify(itrpool, name(SWAPADMIN), [&]( auto& u ) {
                u.weight = weight;
                u.APY = APY;
            });

    }

    void basopooloflp::removelppool(const uint64_t &pool_id)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");

        require_auth(eosio::name(SWAPADMIN));

        auto  itrpool = _lppools.find(pool_id);
        eosio_assert(itrpool != _lppools.end(), "lppool not exist!");
        uint32_t delweight = itrpool->weight;
        //不删除 修改weight 0
        //_lppools.erase(itrpool);   

        _lppools.modify(itrpool, name(SWAPADMIN), [&]( auto& u ) {
                u.state = 3;
                u.weight = 0;
                u.total_staked = 0;
                u.pool_total = 0;
                u.APY = 0;
            });

        global.total_weight -= delweight;
        _global.set(global, name(SWAPADMIN));
    }

    void basopooloflp::setlppool(const uint64_t &mid, const uint8_t &state, const uint16_t &weight, const string &title, const string &desc,
                 const uint8_t &icon, const uint64_t &total_staked, const uint64_t &pool_total, const  double &APY, const string &poolContract, const string &poolCode)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");

        require_auth(eosio::name(SWAPADMIN));

        auto indexmid = _lppools.get_index<"marketid"_n>();
        auto itr = indexmid.lower_bound(mid);
        //mid 默认值为0 不能通过mid 判断是否存在
        auto itrmodify = _lppools.find(itr->poolid);
        if((itrmodify!=_lppools.end()) && (itrmodify->mid == mid))
        {
            uint16_t oldweight = itr->weight;
            // eosio_assert(itrmodify != _lppools.end(), "try setlppool but not find lppool");
            _lppools.modify( itrmodify, name(SWAPADMIN), [&]( auto& u ) {
                    u.state = state; 
                    u.weight = weight;
                    u.title = title;
                    u.desc = desc;
                    u.icon = icon;
                    u.total_staked = total_staked;
                    u.pool_total = pool_total;
                    u.APY = APY;         
            });

            global.total_weight -= oldweight;
            global.total_weight += weight;
            _global.set(global, name(SWAPADMIN));
        } 
        else
        {
            uint64_t newpoolid = _lppools.available_primary_key();
            _lppools.emplace( name(SWAPADMIN), [&]( auto& u ) {
                    u.mid = mid;
                    u.poolid = newpoolid;
                    u.state = state; 
                    u.weight = weight;
                    u.title = title;
                    u.desc = desc;
                    u.icon = icon;
                    u.total_staked = total_staked;
                    u.pool_total = pool_total;
                    u.APY = APY;    
                    u.poolContract = poolContract; 
                    u.scope = poolCode;     
                });
            
            global.maxpoolid = newpoolid;
            global.total_weight += weight;
            _global.set(global, name(SWAPADMIN));
        }       
    }            


    void basopooloflp::updatelppool(const uint64_t &mid, const uint64_t &pool_total, const  double &APY)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");

        require_auth2(capi_name(eosio::name(SWAPADMIN).value), capi_name(eosio::name("cron").value));

        auto indexmid = _lppools.get_index<"marketid"_n>();
        auto itr = indexmid.lower_bound(mid);
        eosio_assert(itr->mid  == mid, "not find this lpmarket!");

        auto itrmodify = _lppools.find(itr->poolid);
        eosio_assert(itrmodify != _lppools.end(), "try updatelppool but not find lppool");

        eosio_assert(itr->state  == 2, "try updatelppool but lppool stopped!");

        _lppools.modify( itrmodify, name(SWAPADMIN), [&]( auto& u ) {
                u.pool_total = pool_total;
                u.APY = APY;         
        });              
    }

    
    void basopooloflp::claim(const eosio::name &from, const uint64_t &pool_id)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");
        require_auth( from );

        asset userbonus = asset(0, BASO_SYMBOL);
        // 领取所有 有id为0的奖池 不能根据0领取所有
        // if(pool_id == 0)
        // {
        //     auto itrpools = _lppools.begin();
        //     while(itrpools != _lppools.end()){
        //         lpuser_table lpusers(name(SWAPADMIN), itrpools->poolid);
        //         auto itruser = lpusers.find(from.value);
        //         if(itruser != lpusers.end())
        //         {
        //             asset idbonus = itruser->unclaimed;

        //             userbonus += idbonus;
        //             lpusers.modify( itruser, name(SWAPADMIN), [&]( auto& u ) {
        //                 u.claimed += idbonus;
        //                 u.unclaimed -= idbonus;          
        //             });
        //         }
        //         itrpools++;
        //     }
        // }
        // else
        {
            lpuser_table lpusers(name(SWAPADMIN), pool_id);
            auto itriduser = lpusers.find(from.value);
            eosio_assert(itriduser != lpusers.end(), "please Add Liquidity first!");
            
            userbonus = itriduser->unclaimed;
            eosio_assert(userbonus.amount > 0, "unclaimed amount must be positve");
            lpusers.modify( itriduser, name(SWAPADMIN), [&]( auto& u ) {
                u.claimed += userbonus;
                u.unclaimed -= userbonus;          
            });
        }

         //判断是否已存在
        auto itruserbonus = _userbonus.find(from.value);
        eosio_assert(itruserbonus != _userbonus.end(), "you have not any Liquidity!");
        // if(pool_id == 0) 
        // {
        //     eosio_assert(itruserbonus->unclaimed == userbonus, "Not equal to userbonus unclaimed data");
        // }

        _userbonus.modify( itruserbonus, name(SWAPADMIN), [&]( auto& r) {     
            r.claimed += userbonus;     
            r.unclaimed -= userbonus;
        }); 

        action(
                permission_level{ eosio::name(POOLDRAW), eosio::name("active")},
                eosio::name(BASOTOKEN),
                eosio::name("transfer"),
                std::make_tuple(eosio::name(POOLDRAW),from, userbonus, std::string("BasoFinance: Add liquidity mining reward"))
            ).send();

    }

    //分发token 按市场ID处理 定时调用 做市过的账户有余额的都保存lpuser 
    void basopooloflp::harvest(const uint64_t &pool_id, const uint32_t &liq_id)
    {
        auto global = _global.get_or_default();
        eosio_assert(global.stopState == 0, "In stop state!");
        require_auth2(capi_name(eosio::name(SWAPADMIN).value), capi_name(eosio::name("cron").value));
        
        //判断阶段挖矿是否已挖完 
        eosio_assert(global.total_mined < STAGE_MINING_TOTAL, "The current mining has finished!");
        
        //判断按顺序执行
        eosio_assert(global.last_harvest_poolid == pool_id, "front pool_id not finish yet!");
        eosio_assert(global.last_harvest_liqid == liq_id, "front liq_id not finish yet!");

        if((pool_id == 0) && (liq_id == 0)) 
        {
            //315s 0.1  1k 1year 
            auto nowtime = now();
            //test 缩短
            //eosio_assert(nowtime - global.last_harvest_time >= 40, "have harvest recently!");
            eosio_assert(nowtime - global.last_harvest_time >= 315, "have harvest recently!");
            global.last_harvest_time = nowtime; 
        }

        struct liqrecord {
            eosio::name owner;
            uint64_t token;
            std::vector<eosio::asset> assets;
            double ratio;
        };

        struct liqlist {
            uint64_t    mid;
            uint64_t    total;
            uint64_t total_lptoken;
            std::vector<liqrecord> liqlist;
            uint64_t primary_key() const { return mid; }
        };
        typedef eosio::multi_index<"liqlist"_n, liqlist> liqlist_table;

        auto  itrpool = _lppools.find(pool_id);
        eosio_assert(itrpool != _lppools.end(), "swappool lppool not exist!");
        //eosio_assert(itrpool->state == 2, "swappool lppool state not right!");

        eosio::asset harvest = asset(0, BASO_SYMBOL);
        bool topoolend = false;
        uint8_t checkliq_to = 0;
        if(itrpool->state == 2)
        {
            liqlist_table liqs(name(SWAPLOG), itrpool->mid);
            lpuser_table lpusers(name(SWAPADMIN), pool_id);

            auto itrliq = liqs.find(itrpool->mid);
            eosio_assert(itrliq != liqs.end(), "swaplog liqpool not exist!");

            eosio::asset poolreward = global.all_pool_reward;
            double totalweight = global.total_weight;
            double poolweight = itrpool->weight;
            poolreward.amount *= (poolweight/totalweight);

            //调试输出
            // string error = "poolreward: " + std::to_string(poolreward.amount); 
            // eosio_assert(false, error.data());

            eosio::asset userunclaimed = poolreward;

            //更新lp pool total_staked
            if(liq_id == 0)
            {
                 _lppools.modify( itrpool, name(SWAPADMIN), [&]( auto& u ) {
                    u.total_staked = itrliq->total_lptoken;       
                });
            }

            //liqlists 市场ID
            
            uint8_t liq_size = itrliq->total;
            double pooltoken = itrliq->total_lptoken; //double pooltoken = itrliq->total_lptoken; pooltoken结果为0
            auto liqlists = itrliq->liqlist;
            uint8_t checkliq_from = liq_id;

            //调试输出
            // if(pool_id == 2)
            // {
            //     string error = " total_lptoken: " + std::to_string(itrliq->total_lptoken)  + " pooltoken: " + std::to_string(pooltoken) ; 
            //     eosio_assert(false, error.data());
            // } 
            
            checkliq_to = checkliq_from + global.once_harvest_num;
            if(checkliq_to > (liq_size -1)) 
            {
                checkliq_to = (liq_size -1);
                topoolend = true;
            }
            for(uint8_t i= checkliq_from; i<= checkliq_to; i++)
            {
                eosio::name owner = liqlists[i].owner;
                double usertoken = liqlists[i].token;
                userunclaimed = poolreward;
                userunclaimed.amount *= (usertoken/pooltoken);//(usertoken/pooltoken);
                // //调试输出
                // if(pool_id == 2)
                // {
                //     string error = " poolreward: " + std::to_string(poolreward.amount)  + " userunclaimed: " + std::to_string(userunclaimed.amount) ; 
                //     eosio_assert(false, error.data());
                // } 

                eosio::asset leftmining = STAGE_MINING_TOTAL - global.total_mined;//为负数
                if(userunclaimed >= leftmining)
                {
                    userunclaimed = leftmining;//要alert 判断要不然为负数
                }
                eosio_assert(userunclaimed.amount <=  poolreward.amount , "user harvest amount should less than poolreward!");

                eosio_assert(userunclaimed.amount >= 0 , "user harvest amount should be positive!");
                // //调试输出
                // if(pool_id == 2)
                // {
                //     string error = " leftmining: " + std::to_string(leftmining.amount)  + " userunclaimed: " + std::to_string(userunclaimed.amount) ; 
                //     eosio_assert(false, error.data());
                // } 
                //判断是否已存在
                auto itruser = lpusers.find(owner.value);
                if (itruser == lpusers.end()) 
                {
                    lpusers.emplace( name(SWAPADMIN), [&]( auto& u ) {
                        u.user = owner;
                        u.staked = liqlists[i].token;
                        u.unclaimed = userunclaimed;
                    });
                }
                else
                {
                    lpusers.modify( itruser, name(SWAPADMIN), [&]( auto& r) {    
                        r.staked = liqlists[i].token;        
                        r.unclaimed += userunclaimed;
                    }); 
                }

                //判断是否已存在
                auto itruserbonus = _userbonus.find(owner.value);
                if (itruserbonus == _userbonus.end()) 
                {
                    _userbonus.emplace( name(SWAPADMIN), [&]( auto& u ) {
                        u.user = owner;
                        u.unclaimed = userunclaimed;
                    });
                }
                else
                {
                    _userbonus.modify( itruserbonus, name(SWAPADMIN), [&]( auto& r) {          
                        r.unclaimed += userunclaimed;
                    }); 
                }

                harvest += userunclaimed;
                
                // //调试输出
                // if(pool_id == 2)
                // {
                //     string error = "poolreward: " + std::to_string(poolreward.amount) + " usertoken: " + std::to_string(usertoken) + " pooltoken: " + std::to_string(pooltoken) + "harvest: " + std::to_string(harvest.amount) + " userunclaimed: " + std::to_string(userunclaimed.amount); 
                //     eosio_assert(false, error.data());
                // } 
            }
        }
        else
        {
            topoolend = true;
        }

        eosio_assert(harvest.amount >= 0 , "round harvest amount should be positive!");

        //更新正在处理的id
        if(topoolend)
        {
            uint8_t nextpoolid = pool_id + 1;
            if(nextpoolid > global.maxpoolid)
            {
                nextpoolid = 0;
            }
            global.last_harvest_poolid = nextpoolid;
            global.last_harvest_liqid = 0;
        }
        else
        {
            global.last_harvest_poolid = pool_id;
            global.last_harvest_liqid = checkliq_to + 1;
        }

        global.total_mined += harvest;
        _global.set(global, eosio::name(SWAPADMIN));
    }

    void basopooloflp::setstop(const uint8_t &state)
    {
        require_auth(eosio::name(SWAPADMIN));
        eosio_assert(state == 0 || state == 1, "set a wrong state!");
        auto global = _global.get_or_default();
        global.stopState = state;
        _global.set(global,eosio::name(SWAPADMIN));
    }
};
