#ifndef _SHADOW_RAIDICCTRIGGERCONTEXT_H
#define _SHADOW_RAIDICCTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidIccTriggers.h"

class RaidIccTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidIccTriggerContext()
    {
        creators["icc lm"] = &RaidIccTriggerContext::icc_lm;

        creators["icc dark reckoning"] = &RaidIccTriggerContext::icc_dark_reckoning;
        creators["icc lady deathwhisper"] = &RaidIccTriggerContext::icc_lady_deathwhisper;

        creators["icc rotting frost giant tank position"] = &RaidIccTriggerContext::icc_rotting_frost_giant_tank_position;
        creators["icc in cannon"] = &RaidIccTriggerContext::icc_in_cannon;
        creators["icc gunship cannon near"] = &RaidIccTriggerContext::icc_gunship_cannon_near;
        creators["icc gunship teleport ally"] = &RaidIccTriggerContext::icc_gunship_teleport_ally;
        creators["icc gunship teleport horde"] = &RaidIccTriggerContext::icc_gunship_teleport_horde;

        creators["icc dbs"] = &RaidIccTriggerContext::icc_dbs;
        creators["icc dbs main tank rune of blood"] = &RaidIccTriggerContext::icc_dbs_main_tank_rune_of_blood;

        creators["icc stinky precious main tank mortal wound"] = &RaidIccTriggerContext::icc_stinky_precious_main_tank_mortal_wound;

        creators["icc festergut group position"] = &RaidIccTriggerContext::icc_festergut_group_position;
        creators["icc festergut main tank gastric bloat"] = &RaidIccTriggerContext::icc_festergut_main_tank_gastric_bloat;
        creators["icc festergut spore"] = &RaidIccTriggerContext::icc_festergut_spore;

        creators["icc rotface tank position"] = &RaidIccTriggerContext::icc_rotface_tank_position;
        creators["icc rotface group position"] = &RaidIccTriggerContext::icc_rotface_group_position;
        creators["icc rotface move away from explosion"] = &RaidIccTriggerContext::icc_rotface_move_away_from_explosion;

        creators["icc putricide volatile ooze"] = &RaidIccTriggerContext::icc_putricide_volatile_ooze;
        creators["icc putricide gas cloud"] = &RaidIccTriggerContext::icc_putricide_gas_cloud;
        creators["icc putricide growing ooze puddle"] = &RaidIccTriggerContext::icc_putricide_growing_ooze_puddle;
        creators["icc putricide main tank mutated plague"] = &RaidIccTriggerContext::icc_putricide_main_tank_mutated_plague;
        creators["icc putricide malleable goo"] = &RaidIccTriggerContext::icc_putricide_malleable_goo;

        creators["icc bpc keleseth tank"] = &RaidIccTriggerContext::icc_bpc_keleseth_tank;
        creators["icc bpc main tank"] = &RaidIccTriggerContext::icc_bpc_main_tank;
        creators["icc bpc empowered vortex"] = &RaidIccTriggerContext::icc_bpc_empowered_vortex;
        creators["icc bpc kinetic bomb"] = &RaidIccTriggerContext::icc_bpc_kinetic_bomb;
        creators["icc bpc ball of flame"] = &RaidIccTriggerContext::icc_bpc_ball_of_flame;

        creators["icc bql group position"] = &RaidIccTriggerContext::icc_bql_group_position;
        creators["icc bql pact of darkfallen"] = &RaidIccTriggerContext::icc_bql_pact_of_darkfallen;
        creators["icc bql vampiric bite"] = &RaidIccTriggerContext::icc_bql_vampiric_bite;

        creators["icc valkyre spear"] = &RaidIccTriggerContext::icc_valkyre_spear;
        creators["icc sister svalna"] = &RaidIccTriggerContext::icc_sister_svalna;

        creators["icc valithria group"] = &RaidIccTriggerContext::icc_valithria_group;
        creators["icc valithria portal"] = &RaidIccTriggerContext::icc_valithria_portal;
        creators["icc valithria heal"] = &RaidIccTriggerContext::icc_valithria_heal;
        creators["icc valithria dream cloud"] = &RaidIccTriggerContext::icc_valithria_dream_cloud;

        creators["icc sindragosa group position"] = &RaidIccTriggerContext::icc_sindragosa_group_position;
        creators["icc sindragosa frost beacon"] = &RaidIccTriggerContext::icc_sindragosa_frost_beacon;
        creators["icc sindragosa blistering cold"] = &RaidIccTriggerContext::icc_sindragosa_blistering_cold;
        creators["icc sindragosa unchained magic"] = &RaidIccTriggerContext::icc_sindragosa_unchained_magic;
        creators["icc sindragosa chilled to the bone"] = &RaidIccTriggerContext::icc_sindragosa_chilled_to_the_bone;
        creators["icc sindragosa mystic buffet"] = &RaidIccTriggerContext::icc_sindragosa_mystic_buffet;
        creators["icc sindragosa main tank mystic buffet"] = &RaidIccTriggerContext::icc_sindragosa_main_tank_mystic_buffet;
        creators["icc sindragosa frost bomb"] = &RaidIccTriggerContext::icc_sindragosa_frost_bomb;
        creators["icc sindragosa tank swap position"] = &RaidIccTriggerContext::icc_sindragosa_tank_swap_position;

        creators["icc lich king shadow trap"] = &RaidIccTriggerContext::icc_lich_king_shadow_trap;
        creators["icc lich king necrotic plague"] = &RaidIccTriggerContext::icc_lich_king_necrotic_plague;
        creators["icc lich king winter"] = &RaidIccTriggerContext::icc_lich_king_winter;
        creators["icc lich king adds"] = &RaidIccTriggerContext::icc_lich_king_adds;
    }

private:
    static Trigger* icc_lm(ShadowAI* ai) { return new IccLmTrigger(ai); }

    static Trigger* icc_dark_reckoning(ShadowAI* ai) { return new IccDarkReckoningTrigger(ai); }
    static Trigger* icc_lady_deathwhisper(ShadowAI* ai) { return new IccLadyDeathwhisperTrigger(ai); }

    static Trigger* icc_rotting_frost_giant_tank_position(ShadowAI* ai) { return new IccRottingFrostGiantTankPositionTrigger(ai); }
    static Trigger* icc_in_cannon(ShadowAI* ai) { return new IccInCannonTrigger(ai); }
    static Trigger* icc_gunship_cannon_near(ShadowAI* ai) { return new IccGunshipCannonNearTrigger(ai); }
    static Trigger* icc_gunship_teleport_ally(ShadowAI* ai) { return new IccGunshipTeleportAllyTrigger(ai); }
    static Trigger* icc_gunship_teleport_horde(ShadowAI* ai) { return new IccGunshipTeleportHordeTrigger(ai); }

    static Trigger* icc_dbs(ShadowAI* ai) { return new IccDbsTrigger(ai); }
    static Trigger* icc_dbs_main_tank_rune_of_blood(ShadowAI* ai) { return new IccDbsMainTankRuneOfBloodTrigger(ai); }

    static Trigger* icc_stinky_precious_main_tank_mortal_wound(ShadowAI* ai) { return new IccStinkyPreciousMainTankMortalWoundTrigger(ai); }

    static Trigger* icc_festergut_group_position(ShadowAI* ai) { return new IccFestergutGroupPositionTrigger(ai); }
    static Trigger* icc_festergut_main_tank_gastric_bloat(ShadowAI* ai) { return new IccFestergutMainTankGastricBloatTrigger(ai); }
    static Trigger* icc_festergut_spore(ShadowAI* ai) { return new IccFestergutSporeTrigger(ai); }

    static Trigger* icc_rotface_tank_position(ShadowAI* ai) { return new IccRotfaceTankPositionTrigger(ai); }
    static Trigger* icc_rotface_group_position(ShadowAI* ai) { return new IccRotfaceGroupPositionTrigger(ai); }
    static Trigger* icc_rotface_move_away_from_explosion(ShadowAI* ai) { return new IccRotfaceMoveAwayFromExplosionTrigger(ai); }

    static Trigger* icc_putricide_volatile_ooze(ShadowAI* ai) { return new IccPutricideVolatileOozeTrigger(ai); }
    static Trigger* icc_putricide_gas_cloud(ShadowAI* ai) { return new IccPutricideGasCloudTrigger(ai); }
    static Trigger* icc_putricide_growing_ooze_puddle(ShadowAI* ai) { return new IccPutricideGrowingOozePuddleTrigger(ai); }
    static Trigger* icc_putricide_main_tank_mutated_plague(ShadowAI* ai) { return new IccPutricideMainTankMutatedPlagueTrigger(ai); }
    static Trigger* icc_putricide_malleable_goo(ShadowAI* ai) { return new IccPutricideMalleableGooTrigger(ai); }

    static Trigger* icc_bpc_keleseth_tank(ShadowAI* ai) { return new IccBpcKelesethTankTrigger(ai); }
    static Trigger* icc_bpc_main_tank(ShadowAI* ai) { return new IccBpcMainTankTrigger(ai); }
    static Trigger* icc_bpc_empowered_vortex(ShadowAI* ai) { return new IccBpcEmpoweredVortexTrigger(ai); }
    static Trigger* icc_bpc_kinetic_bomb(ShadowAI* ai) { return new IccBpcKineticBombTrigger(ai); }
    static Trigger* icc_bpc_ball_of_flame(ShadowAI* ai) { return new IccBpcBallOfFlameTrigger(ai); }

    static Trigger* icc_bql_group_position(ShadowAI* ai) { return new IccBqlGroupPositionTrigger(ai); }
    static Trigger* icc_bql_pact_of_darkfallen(ShadowAI* ai) { return new IccBqlPactOfDarkfallenTrigger(ai); }
    static Trigger* icc_bql_vampiric_bite(ShadowAI* ai) { return new IccBqlVampiricBiteTrigger(ai); }

    static Trigger* icc_valkyre_spear(ShadowAI* ai) { return new IccValkyreSpearTrigger(ai); }
    static Trigger* icc_sister_svalna(ShadowAI* ai) { return new IccSisterSvalnaTrigger(ai); }

    static Trigger* icc_valithria_group(ShadowAI* ai) { return new IccValithriaGroupTrigger(ai); }
    static Trigger* icc_valithria_portal(ShadowAI* ai) { return new IccValithriaPortalTrigger(ai); }
    static Trigger* icc_valithria_heal(ShadowAI* ai) { return new IccValithriaHealTrigger(ai); }
    static Trigger* icc_valithria_dream_cloud(ShadowAI* ai) { return new IccValithriaDreamCloudTrigger(ai); }

    static Trigger* icc_sindragosa_group_position(ShadowAI* ai) { return new IccSindragosaGroupPositionTrigger(ai); }
    static Trigger* icc_sindragosa_frost_beacon(ShadowAI* ai) { return new IccSindragosaFrostBeaconTrigger(ai); }
    static Trigger* icc_sindragosa_blistering_cold(ShadowAI* ai) { return new IccSindragosaBlisteringColdTrigger(ai); }
    static Trigger* icc_sindragosa_unchained_magic(ShadowAI* ai) { return new IccSindragosaUnchainedMagicTrigger(ai); }
    static Trigger* icc_sindragosa_chilled_to_the_bone(ShadowAI* ai) { return new IccSindragosaChilledToTheBoneTrigger(ai); }
    static Trigger* icc_sindragosa_mystic_buffet(ShadowAI* ai) { return new IccSindragosaMysticBuffetTrigger(ai); }
    static Trigger* icc_sindragosa_main_tank_mystic_buffet(ShadowAI* ai) { return new IccSindragosaMainTankMysticBuffetTrigger(ai); }
    static Trigger* icc_sindragosa_frost_bomb(ShadowAI* ai) { return new IccSindragosaFrostBombTrigger(ai); }
    static Trigger* icc_sindragosa_tank_swap_position(ShadowAI* ai) { return new IccSindragosaTankSwapPositionTrigger(ai); }

    static Trigger* icc_lich_king_shadow_trap(ShadowAI* ai) { return new IccLichKingShadowTrapTrigger(ai); }
    static Trigger* icc_lich_king_necrotic_plague(ShadowAI* ai) { return new IccLichKingNecroticPlagueTrigger(ai); }
    static Trigger* icc_lich_king_winter(ShadowAI* ai) { return new IccLichKingWinterTrigger(ai); }
    static Trigger* icc_lich_king_adds(ShadowAI* ai) { return new IccLichKingAddsTrigger(ai); }

};

#endif
