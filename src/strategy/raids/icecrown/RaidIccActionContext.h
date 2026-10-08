#ifndef _SHADOW_RAIDICCACTIONCONTEXT_H
#define _SHADOW_RAIDICCACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidIccActions.h"

class RaidIccActionContext : public NamedObjectContext<Action>
{
public:
    RaidIccActionContext()
    {
        creators["icc lm tank position"] = &RaidIccActionContext::icc_lm_tank_position;
        creators["icc spike"] = &RaidIccActionContext::icc_spike;

        creators["icc dark reckoning"] = &RaidIccActionContext::icc_dark_reckoning;
        creators["icc ranged position lady deathwhisper"] = &RaidIccActionContext::icc_ranged_position_lady_deathwhisper;
        creators["icc adds lady deathwhisper"] = &RaidIccActionContext::icc_adds_lady_deathwhisper;
        creators["icc shade lady deathwhisper"] = &RaidIccActionContext::icc_shade_lady_deathwhisper;

        creators["icc rotting frost giant tank position"] = &RaidIccActionContext::icc_rotting_frost_giant_tank_position;
        creators["icc cannon fire"] = &RaidIccActionContext::icc_cannon_fire;
        creators["icc gunship enter cannon"] = &RaidIccActionContext::icc_gunship_enter_cannon;
        creators["icc gunship teleport ally"] = &RaidIccActionContext::icc_gunship_teleport_ally;
        creators["icc gunship teleport horde"] = &RaidIccActionContext::icc_gunship_teleport_horde;

        creators["icc dbs tank position"] = &RaidIccActionContext::icc_dbs_tank_position;
        creators["icc adds dbs"] = &RaidIccActionContext::icc_adds_dbs;

        creators["icc festergut group position"] = &RaidIccActionContext::icc_festergut_group_position;
        creators["icc festergut spore"] = &RaidIccActionContext::icc_festergut_spore;

        creators["icc rotface tank position"] = &RaidIccActionContext::icc_rotface_tank_position;
        creators["icc rotface group position"] = &RaidIccActionContext::icc_rotface_group_position;
        creators["icc rotface move away from explosion"] = &RaidIccActionContext::icc_rotface_move_away_from_explosion;

        creators["icc putricide volatile ooze"] = &RaidIccActionContext::icc_putricide_volatile_ooze;
        creators["icc putricide gas cloud"] = &RaidIccActionContext::icc_putricide_gas_cloud;
        creators["icc putricide growing ooze puddle"] = &RaidIccActionContext::icc_putricide_growing_ooze_puddle;
        creators["icc putricide avoid malleable goo"] = &RaidIccActionContext::icc_putricide_avoid_malleable_goo;

        creators["icc bpc keleseth tank"] = &RaidIccActionContext::icc_bpc_keleseth_tank;
        creators["icc bpc main tank"] = &RaidIccActionContext::icc_bpc_main_tank;
        creators["icc bpc empowered vortex"] = &RaidIccActionContext::icc_bpc_empowered_vortex;
        creators["icc bpc kinetic bomb"] = &RaidIccActionContext::icc_bpc_kinetic_bomb;
        creators["icc bpc ball of flame"] = &RaidIccActionContext::icc_bpc_ball_of_flame;

        creators["icc bql group position"] = &RaidIccActionContext::icc_bql_group_position;
        creators["icc bql pact of darkfallen"] = &RaidIccActionContext::icc_bql_pact_of_darkfallen;
        creators["icc bql vampiric bite"] = &RaidIccActionContext::icc_bql_vampiric_bite;

        creators["icc valkyre spear"] = &RaidIccActionContext::icc_valkyre_spear;
        creators["icc sister svalna"] = &RaidIccActionContext::icc_sister_svalna;

        creators["icc valithria group"] = &RaidIccActionContext::icc_valithria_group;
        creators["icc valithria portal"] = &RaidIccActionContext::icc_valithria_portal;
        creators["icc valithria heal"] = &RaidIccActionContext::icc_valithria_heal;
        creators["icc valithria dream cloud"] = &RaidIccActionContext::icc_valithria_dream_cloud;

        creators["icc sindragosa group position"] = &RaidIccActionContext::icc_sindragosa_group_position;
        creators["icc sindragosa frost beacon"] = &RaidIccActionContext::icc_sindragosa_frost_beacon;
        creators["icc sindragosa blistering cold"] = &RaidIccActionContext::icc_sindragosa_blistering_cold;
        creators["icc sindragosa unchained magic"] = &RaidIccActionContext::icc_sindragosa_unchained_magic;
        creators["icc sindragosa chilled to the bone"] = &RaidIccActionContext::icc_sindragosa_chilled_to_the_bone;
        creators["icc sindragosa mystic buffet"] = &RaidIccActionContext::icc_sindragosa_mystic_buffet;
        creators["icc sindragosa frost bomb"] = &RaidIccActionContext::icc_sindragosa_frost_bomb;
        creators["icc sindragosa tank swap position"] = &RaidIccActionContext::icc_sindragosa_tank_swap_position;

        creators["icc lich king shadow trap"] = &RaidIccActionContext::icc_lich_king_shadow_trap;
        creators["icc lich king necrotic plague"] = &RaidIccActionContext::icc_lich_king_necrotic_plague;
        creators["icc lich king winter"] = &RaidIccActionContext::icc_lich_king_winter;
        creators["icc lich king adds"] = &RaidIccActionContext::icc_lich_king_adds;
    }

private:
    static Action* icc_lm_tank_position(ShadowAI* ai) { return new IccLmTankPositionAction(ai); }
    static Action* icc_spike(ShadowAI* ai) { return new IccSpikeAction(ai); }

    static Action* icc_dark_reckoning(ShadowAI* ai) { return new IccDarkReckoningAction(ai); }
    static Action* icc_ranged_position_lady_deathwhisper(ShadowAI* ai) { return new IccRangedPositionLadyDeathwhisperAction(ai); }
    static Action* icc_adds_lady_deathwhisper(ShadowAI* ai) { return new IccAddsLadyDeathwhisperAction(ai); }
    static Action* icc_shade_lady_deathwhisper(ShadowAI* ai) { return new IccShadeLadyDeathwhisperAction(ai); }

    static Action* icc_rotting_frost_giant_tank_position(ShadowAI* ai) { return new IccRottingFrostGiantTankPositionAction(ai); }
    static Action* icc_cannon_fire(ShadowAI* ai) { return new IccCannonFireAction(ai); }
    static Action* icc_gunship_enter_cannon(ShadowAI* ai) { return new IccGunshipEnterCannonAction(ai); }
    static Action* icc_gunship_teleport_ally(ShadowAI* ai) { return new IccGunshipTeleportAllyAction(ai); }
    static Action* icc_gunship_teleport_horde(ShadowAI* ai) { return new IccGunshipTeleportHordeAction(ai); }

    static Action* icc_dbs_tank_position(ShadowAI* ai) { return new IccDbsTankPositionAction(ai); }
    static Action* icc_adds_dbs(ShadowAI* ai) { return new IccAddsDbsAction(ai); }

    static Action* icc_festergut_group_position(ShadowAI* ai) { return new IccFestergutGroupPositionAction(ai); }
    static Action* icc_festergut_spore(ShadowAI* ai) { return new IccFestergutSporeAction(ai); }

    static Action* icc_rotface_tank_position(ShadowAI* ai) { return new IccRotfaceTankPositionAction(ai); }
    static Action* icc_rotface_group_position(ShadowAI* ai) { return new IccRotfaceGroupPositionAction(ai); }
    static Action* icc_rotface_move_away_from_explosion(ShadowAI* ai) { return new IccRotfaceMoveAwayFromExplosionAction(ai); }

    static Action* icc_putricide_volatile_ooze(ShadowAI* ai) { return new IccPutricideVolatileOozeAction(ai); }
    static Action* icc_putricide_gas_cloud(ShadowAI* ai) { return new IccPutricideGasCloudAction(ai); }
    static Action* icc_putricide_growing_ooze_puddle(ShadowAI* ai) { return new IccPutricideGrowingOozePuddleAction(ai); }
    static Action* icc_putricide_avoid_malleable_goo(ShadowAI* ai) { return new IccPutricideAvoidMalleableGooAction(ai); }

    static Action* icc_bpc_keleseth_tank(ShadowAI* ai) { return new IccBpcKelesethTankAction(ai); }
    static Action* icc_bpc_main_tank(ShadowAI* ai) { return new IccBpcMainTankAction(ai); }
    static Action* icc_bpc_empowered_vortex(ShadowAI* ai) { return new IccBpcEmpoweredVortexAction(ai); }
    static Action* icc_bpc_kinetic_bomb(ShadowAI* ai) { return new IccBpcKineticBombAction(ai); }
    static Action* icc_bpc_ball_of_flame(ShadowAI* ai) { return new IccBpcBallOfFlameAction(ai); }

    static Action* icc_bql_group_position(ShadowAI* ai) { return new IccBqlGroupPositionAction(ai); }
    static Action* icc_bql_pact_of_darkfallen(ShadowAI* ai) { return new IccBqlPactOfDarkfallenAction(ai); }
    static Action* icc_bql_vampiric_bite(ShadowAI* ai) { return new IccBqlVampiricBiteAction(ai); }

    static Action* icc_valkyre_spear(ShadowAI* ai) { return new IccValkyreSpearAction(ai); }
    static Action* icc_sister_svalna(ShadowAI* ai) { return new IccSisterSvalnaAction(ai); }

    static Action* icc_valithria_group(ShadowAI* ai) { return new IccValithriaGroupAction(ai); }
    static Action* icc_valithria_portal(ShadowAI* ai) { return new IccValithriaPortalAction(ai); }
    static Action* icc_valithria_heal(ShadowAI* ai) { return new IccValithriaHealAction(ai); }
    static Action* icc_valithria_dream_cloud(ShadowAI* ai) { return new IccValithriaDreamCloudAction(ai); }

    static Action* icc_sindragosa_group_position(ShadowAI* ai) { return new IccSindragosaGroupPositionAction(ai); }
    static Action* icc_sindragosa_frost_beacon(ShadowAI* ai) { return new IccSindragosaFrostBeaconAction(ai); }
    static Action* icc_sindragosa_blistering_cold(ShadowAI* ai) { return new IccSindragosaBlisteringColdAction(ai); }
    static Action* icc_sindragosa_unchained_magic(ShadowAI* ai) { return new IccSindragosaUnchainedMagicAction(ai); }
    static Action* icc_sindragosa_chilled_to_the_bone(ShadowAI* ai) { return new IccSindragosaChilledToTheBoneAction(ai); }
    static Action* icc_sindragosa_mystic_buffet(ShadowAI* ai) { return new IccSindragosaMysticBuffetAction(ai); }
    static Action* icc_sindragosa_frost_bomb(ShadowAI* ai) { return new IccSindragosaFrostBombAction(ai); }
    static Action* icc_sindragosa_tank_swap_position(ShadowAI* ai) { return new IccSindragosaTankSwapPositionAction(ai); }

    static Action* icc_lich_king_shadow_trap(ShadowAI* ai) { return new IccLichKingShadowTrapAction(ai); }
    static Action* icc_lich_king_necrotic_plague(ShadowAI* ai) { return new IccLichKingNecroticPlagueAction(ai); }
    static Action* icc_lich_king_winter(ShadowAI* ai) { return new IccLichKingWinterAction(ai); }
    static Action* icc_lich_king_adds(ShadowAI* ai) { return new IccLichKingAddsAction(ai); }

};

#endif
