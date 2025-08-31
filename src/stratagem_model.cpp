#include "stratagem_model.hpp"

using namespace stratadex;

static StratagemModel *instance = nullptr;
StratagemModel *StratagemModel::getInstance()
{
    if(instance == nullptr){
        instance = new StratagemModel(nullptr);
    } 
    return instance;
}

std::unordered_map<std::string, Stratagem> stratadex::StratagemModel::getAllStratagems()
{
    return this->allStratagems;
}

std::unordered_map<std::string, Stratagem> StratagemModel::getActiveStratagems()
{
    return this->activeStratagems;
}

size_t StratagemModel::getNumExercises()
{
    return this->numberOfExercises;
}

void stratadex::StratagemModel::setNumExercises(size_t numExercises)
{
    this->numberOfExercises = numExercises;
}

void StratagemModel::appendActiveStrat(std::string strat_name)
{
    // If we can find it here, continue.
    if(allStratagems.find(strat_name) != allStratagems.end()){
        Stratagem strat = allStratagems.at(strat_name);

        // If we can find it here, stop.
        if(activeStratagems.find(strat_name) == activeStratagems.end()){
            activeStratagems.insert({strat_name, strat});
            emit activeStratAdded(strat_name);
        }
    }
}

void StratagemModel::removeActiveStrat(std::string strat_name)
{
    this->activeStratagems.erase(strat_name);
}

StratagemModel::StratagemModel(QObject *parent) :
QObject(parent)
{
    numberOfExercises = 0;

    
	Stratagem am_23_ems_mortar_sentry("Am 23 Ems Mortar Sentry", {DOWN,UP,RIGHT,DOWN,RIGHT});
    allStratagems.insert({am_23_ems_mortar_sentry.getName(), am_23_ems_mortar_sentry});
    
	Stratagem anti_materiel_rifle("Anti Materiel Rifle", {DOWN,LEFT,RIGHT,UP,DOWN});
    allStratagems.insert({anti_materiel_rifle.getName(), anti_materiel_rifle});
    
	Stratagem anti_personnel_minefield("Anti Personnel Minefield", {DOWN , LEFT , UP , RIGHT});
    allStratagems.insert({anti_personnel_minefield.getName(), anti_personnel_minefield});
    
	Stratagem arc_thrower("Arc Thrower", {DOWN , RIGHT , DOWN , UP , LEFT , LEFT});
    allStratagems.insert({arc_thrower.getName(), arc_thrower});
    
	Stratagem autocannon_sentry("Autocannon Sentry", {DOWN , UP , RIGHT , UP , LEFT , UP});
    allStratagems.insert({autocannon_sentry.getName(), autocannon_sentry});
    
	Stratagem autocannon("Autocannon", {DOWN , LEFT , DOWN , UP , UP , RIGHT});
    allStratagems.insert({autocannon.getName(), autocannon});
    
	Stratagem ax_arc_3__guard_dog__k_9("Ax Arc 3  Guard Dog  K 9", {DOWN , UP , LEFT , UP , RIGHT , LEFT});
    allStratagems.insert({ax_arc_3__guard_dog__k_9.getName(), ax_arc_3__guard_dog__k_9});
    
	Stratagem a_flam_40_flame_sentry("A Flam 40 Flame Sentry", {DOWN , UP , RIGHT , DOWN , UP , UP});
    allStratagems.insert({a_flam_40_flame_sentry.getName(), a_flam_40_flame_sentry});
    
	Stratagem a_las_98_laser_sentry("A Las 98 Laser Sentry", {DOWN , UP , RIGHT , DOWN , UP , RIGHT});
    allStratagems.insert({a_las_98_laser_sentry.getName(), a_las_98_laser_sentry});
    
	Stratagem ballistic_shield_backpack("Ballistic Shield Backpack", {DOWN , LEFT , DOWN , DOWN , UP , LEFT});
    allStratagems.insert({ballistic_shield_backpack.getName(), ballistic_shield_backpack});
    
	Stratagem commando("Commando", {DOWN , LEFT , UP , DOWN , RIGHT});
    allStratagems.insert({commando.getName(), commando});
    
	Stratagem cqc_1_one_true_flag("Cqc 1 One True Flag", {DOWN , LEFT , RIGHT , RIGHT , UP});
    allStratagems.insert({cqc_1_one_true_flag.getName(), cqc_1_one_true_flag});
    
	Stratagem dark_fluid_vessel("Dark Fluid Vessel", {UP , LEFT , RIGHT , DOWN , UP , UP});
    allStratagems.insert({dark_fluid_vessel.getName(), dark_fluid_vessel});
    
	Stratagem eagle_110mm_rocket_pods("Eagle 110mm Rocket Pods", {UP , RIGHT , UP , LEFT});
    allStratagems.insert({eagle_110mm_rocket_pods.getName(), eagle_110mm_rocket_pods});
    
	Stratagem eagle_500kg_bomb("Eagle 500kg Bomb", {UP , RIGHT , DOWN , DOWN , DOWN});
    allStratagems.insert({eagle_500kg_bomb.getName(), eagle_500kg_bomb});
    
	Stratagem eagle_airstrike("Eagle Airstrike", {UP , RIGHT , DOWN , RIGHT});
    allStratagems.insert({eagle_airstrike.getName(), eagle_airstrike});
    
	Stratagem eagle_cluster_bomb("Eagle Cluster Bomb", {UP , RIGHT , DOWN , DOWN , RIGHT});
    allStratagems.insert({eagle_cluster_bomb.getName(), eagle_cluster_bomb});
    
	Stratagem eagle_napalm_airstrike("Eagle Napalm Airstrike", {UP , RIGHT , DOWN , UP});
    allStratagems.insert({eagle_napalm_airstrike.getName(), eagle_napalm_airstrike});
    
	Stratagem eagle_rearm("Eagle Rearm", {UP , UP , LEFT , UP , RIGHT});
    allStratagems.insert({eagle_rearm.getName(), eagle_rearm});
    
	Stratagem eagle_smoke_strike("Eagle Smoke Strike", {UP , RIGHT , UP , DOWN});
    allStratagems.insert({eagle_smoke_strike.getName(), eagle_smoke_strike});
    
	Stratagem eagle_strafing_run("Eagle Strafing Run", {UP , RIGHT , RIGHT});
    allStratagems.insert({eagle_strafing_run.getName(), eagle_strafing_run});
    
	Stratagem exo_45_patriot_exosuit("Exo 45 Patriot Exosuit", {LEFT , DOWN , RIGHT , UP , LEFT , DOWN , DOWN});
    allStratagems.insert({exo_45_patriot_exosuit.getName(), exo_45_patriot_exosuit});
    
	Stratagem exo_49_emancipator_exosuit("Exo 49 Emancipator Exosuit", {LEFT , DOWN , RIGHT , UP , LEFT , DOWN , UP});
    allStratagems.insert({exo_49_emancipator_exosuit.getName(), exo_49_emancipator_exosuit});
    
	Stratagem expendable_anti_tank("Expendable Anti Tank", {DOWN , DOWN , LEFT , UP , RIGHT});
    allStratagems.insert({expendable_anti_tank.getName(), expendable_anti_tank});
    
	Stratagem e_at_12_anti_tank_emplacement("E At 12 Anti Tank Emplacement", {DOWN , UP , LEFT , RIGHT , RIGHT , RIGHT});
    allStratagems.insert({e_at_12_anti_tank_emplacement.getName(), e_at_12_anti_tank_emplacement});
    
	Stratagem flamethrower("Flamethrower", {DOWN , LEFT , UP , DOWN , UP});
    allStratagems.insert({flamethrower.getName(), flamethrower});
    
	Stratagem gas_minefield("Gas Minefield", {DOWN , LEFT , LEFT , RIGHT});
    allStratagems.insert({gas_minefield.getName(), gas_minefield});
    
	Stratagem gatling_sentry("Gatling Sentry", {DOWN , UP , RIGHT , LEFT});
    allStratagems.insert({gatling_sentry.getName(), gatling_sentry});
    
	Stratagem gl_21_grenadier_battlement("Gl 21 Grenadier Battlement", {DOWN , RIGHT , DOWN , LEFT , RIGHT});
    allStratagems.insert({gl_21_grenadier_battlement.getName(), gl_21_grenadier_battlement});
    
	Stratagem gl_52_de_escalator("Gl 52 De Escalator", {LEFT , RIGHT , UP , LEFT , RIGHT});
    allStratagems.insert({gl_52_de_escalator.getName(), gl_52_de_escalator});
    
	Stratagem grenade_launcher("Grenade Launcher", {DOWN , LEFT , UP , LEFT , DOWN});
    allStratagems.insert({grenade_launcher.getName(), grenade_launcher});
    
	Stratagem guard_dog_dog_breath("Guard Dog Dog Breath", {DOWN , UP , LEFT , UP , RIGHT , UP});
    allStratagems.insert({guard_dog_dog_breath.getName(), guard_dog_dog_breath});
    
	Stratagem guard_dog_rover("Guard Dog Rover", {DOWN , UP , LEFT , UP , RIGHT , RIGHT});
    allStratagems.insert({guard_dog_rover.getName(), guard_dog_rover});
    
	Stratagem guard_dog("Guard Dog", {DOWN , UP , LEFT , UP , RIGHT , DOWN});
    allStratagems.insert({guard_dog.getName(), guard_dog});
    
	Stratagem heavy_machine_gun("Heavy Machine Gun", {DOWN , LEFT , UP , DOWN , DOWN});
    allStratagems.insert({heavy_machine_gun.getName(), heavy_machine_gun});
    
	Stratagem hellbomb("Hellbomb", {DOWN , UP , LEFT , DOWN , UP , RIGHT , DOWN , UP});
    allStratagems.insert({hellbomb.getName(), hellbomb});
    
	Stratagem hmg_emplacement("Hmg Emplacement", {DOWN , UP , LEFT , RIGHT , RIGHT , LEFT});
    allStratagems.insert({hmg_emplacement.getName(), hmg_emplacement});
    
	Stratagem hover_pack("Hover Pack", {DOWN , UP , UP , DOWN , LEFT , RIGHT});
    allStratagems.insert({hover_pack.getName(), hover_pack});
    
	Stratagem incendiary_mines("Incendiary Mines", {DOWN , LEFT , LEFT , DOWN});
    allStratagems.insert({incendiary_mines.getName(), incendiary_mines});
    
	Stratagem jump_pack("Jump Pack", {DOWN , UP , UP , DOWN , UP});
    allStratagems.insert({jump_pack.getName(), jump_pack});
    
	Stratagem laser_cannon("Laser Cannon", {DOWN , LEFT , DOWN , UP , LEFT});
    allStratagems.insert({laser_cannon.getName(), laser_cannon});
    
	Stratagem lift_182_warp_pack("Lift 182 Warp Pack", {DOWN , LEFT , RIGHT , DOWN , LEFT , RIGHT});
    allStratagems.insert({lift_182_warp_pack.getName(), lift_182_warp_pack});
    
	Stratagem m_102_fast_recon_vehicle("M 102 Fast Recon Vehicle", {LEFT , DOWN , RIGHT , DOWN , RIGHT , DOWN , UP});
    allStratagems.insert({m_102_fast_recon_vehicle.getName(), m_102_fast_recon_vehicle});
    
	Stratagem machine_gun_sentry("Machine Gun Sentry", {DOWN , UP , RIGHT , RIGHT , UP});
    allStratagems.insert({machine_gun_sentry.getName(), machine_gun_sentry});
    
	Stratagem machine_gun("Machine Gun", {DOWN , LEFT , DOWN , UP , RIGHT});
    allStratagems.insert({machine_gun.getName(), machine_gun});
    
	Stratagem md_17_anti_tank_mines("Md 17 Anti Tank Mines", {DOWN , LEFT , UP , UP});
    allStratagems.insert({md_17_anti_tank_mines.getName(), md_17_anti_tank_mines});
    
	Stratagem mortar_sentry("Mortar Sentry", {DOWN , UP , RIGHT , RIGHT , DOWN});
    allStratagems.insert({mortar_sentry.getName(), mortar_sentry});
    
	Stratagem orbital_120mm_he_barrage("Orbital 120mm He Barrage", {RIGHT , RIGHT , DOWN , LEFT , RIGHT , DOWN});
    allStratagems.insert({orbital_120mm_he_barrage.getName(), orbital_120mm_he_barrage});
    
	Stratagem orbital_380mm_he_barrage("Orbital 380mm He Barrage", {RIGHT , DOWN , UP , UP , LEFT , DOWN , DOWN});
    allStratagems.insert({orbital_380mm_he_barrage.getName(), orbital_380mm_he_barrage});
    
	Stratagem orbital_airburst_strike("Orbital Airburst Strike", {RIGHT , RIGHT , RIGHT});
    allStratagems.insert({orbital_airburst_strike.getName(), orbital_airburst_strike});
    
	Stratagem orbital_ems_strike("Orbital Ems Strike", {RIGHT , RIGHT , LEFT , DOWN});
    allStratagems.insert({orbital_ems_strike.getName(), orbital_ems_strike});
    
	Stratagem orbital_gas_strike("Orbital Gas Strike", {RIGHT , RIGHT , DOWN , RIGHT});
    allStratagems.insert({orbital_gas_strike.getName(), orbital_gas_strike});
    
	Stratagem orbital_gatling_barrage("Orbital Gatling Barrage", {RIGHT , DOWN , LEFT , UP , UP});
    allStratagems.insert({orbital_gatling_barrage.getName(), orbital_gatling_barrage});
    
	Stratagem orbital_illumination_flare("Orbital Illumination Flare", {RIGHT , RIGHT , LEFT , LEFT});
    allStratagems.insert({orbital_illumination_flare.getName(), orbital_illumination_flare});
    
	Stratagem orbital_laser("Orbital Laser", {RIGHT , DOWN , UP , RIGHT , DOWN});
    allStratagems.insert({orbital_laser.getName(), orbital_laser});
    
	Stratagem orbital_napalm_barrage("Orbital Napalm Barrage", {RIGHT , RIGHT , DOWN , LEFT , RIGHT , UP});
    allStratagems.insert({orbital_napalm_barrage.getName(), orbital_napalm_barrage});
    
	Stratagem orbital_precision_strike("Orbital Precision Strike", {RIGHT , RIGHT , UP});
    allStratagems.insert({orbital_precision_strike.getName(), orbital_precision_strike});
    
	Stratagem orbital_railcannon_strike("Orbital Railcannon Strike", {RIGHT , UP , DOWN , DOWN , RIGHT});
    allStratagems.insert({orbital_railcannon_strike.getName(), orbital_railcannon_strike});
    
	Stratagem orbital_smoke_strike("Orbital Smoke Strike", {RIGHT , RIGHT , DOWN , UP});
    allStratagems.insert({orbital_smoke_strike.getName(), orbital_smoke_strike});
    
	Stratagem orbital_walking_barrage("Orbital Walking Barrage", {RIGHT , DOWN , RIGHT , DOWN , RIGHT , DOWN});
    allStratagems.insert({orbital_walking_barrage.getName(), orbital_walking_barrage});
    
	Stratagem plas_45_epoch("Plas 45 Epoch", {DOWN , LEFT , UP , LEFT , RIGHT});
    allStratagems.insert({plas_45_epoch.getName(), plas_45_epoch});
    
	Stratagem portable_hellbomb("Portable Hellbomb", {DOWN , RIGHT , UP , UP , UP});
    allStratagems.insert({portable_hellbomb.getName(), portable_hellbomb});
    
	Stratagem prospecting_drill("Prospecting Drill", {DOWN , DOWN , LEFT , RIGHT , DOWN , DOWN});
    allStratagems.insert({prospecting_drill.getName(), prospecting_drill});
    
	Stratagem quasar_cannon("Quasar Cannon", {DOWN , DOWN , UP , LEFT , RIGHT});
    allStratagems.insert({quasar_cannon.getName(), quasar_cannon});
    
	Stratagem railgun("Railgun", {DOWN , RIGHT , DOWN , UP , LEFT , RIGHT});
    allStratagems.insert({railgun.getName(), railgun});
    
	Stratagem recoilless_rifle("Recoilless Rifle", {DOWN , LEFT , RIGHT , RIGHT , LEFT});
    allStratagems.insert({recoilless_rifle.getName(), recoilless_rifle});
    
	Stratagem reinforce("Reinforce", {UP , DOWN , RIGHT , LEFT , UP});
    allStratagems.insert({reinforce.getName(), reinforce});
    
	Stratagem resupply("Resupply", {DOWN , DOWN , UP , RIGHT});
    allStratagems.insert({resupply.getName(), resupply});
    
	Stratagem rl_77_airburst_rocket_launcher("Rl 77 Airburst Rocket Launcher", {DOWN , UP , UP , LEFT , RIGHT});
    allStratagems.insert({rl_77_airburst_rocket_launcher.getName(), rl_77_airburst_rocket_launcher});
    
	Stratagem rocket_sentry("Rocket Sentry", {DOWN , UP , RIGHT , RIGHT , LEFT});
    allStratagems.insert({rocket_sentry.getName(), rocket_sentry});
    
	Stratagem seaf_artillery("Seaf Artillery", {RIGHT , UP , UP , DOWN});
    allStratagems.insert({seaf_artillery.getName(), seaf_artillery});
    
	Stratagem seismic_probe("Seismic Probe", {UP , UP , LEFT , RIGHT , DOWN , DOWN});
    allStratagems.insert({seismic_probe.getName(), seismic_probe});
    
	Stratagem sh_51_directional_shield("Sh 51 Directional Shield", {DOWN , UP , LEFT , RIGHT , UP , UP});
    allStratagems.insert({sh_51_directional_shield.getName(), sh_51_directional_shield});
    
	Stratagem shield_generator_pack("Shield Generator Pack", {DOWN , UP , LEFT , RIGHT , LEFT , RIGHT});
    allStratagems.insert({shield_generator_pack.getName(), shield_generator_pack});
    
	Stratagem shield_generator_relay("Shield Generator Relay", {DOWN , DOWN , LEFT , RIGHT , LEFT , RIGHT});
    allStratagems.insert({shield_generator_relay.getName(), shield_generator_relay});
    
	Stratagem sos_beacon("Sos Beacon", {UP , DOWN , RIGHT , UP});
    allStratagems.insert({sos_beacon.getName(), sos_beacon});
    
	Stratagem spear("Spear", {DOWN , DOWN , UP , DOWN , DOWN});
    allStratagems.insert({spear.getName(), spear});
    
	Stratagem sta_x3("Sta X3", {DOWN , DOWN , UP , DOWN , RIGHT});
    allStratagems.insert({sta_x3.getName(), sta_x3});
    
	Stratagem stalwart("Stalwart", {DOWN , LEFT , DOWN , UP , UP , LEFT});
    allStratagems.insert({stalwart.getName(), stalwart});
    
	Stratagem sterilizer("Sterilizer", {DOWN , LEFT , UP , DOWN , LEFT});
    allStratagems.insert({sterilizer.getName(), sterilizer});
    
	Stratagem super_earth_flag("Super Earth Flag", {DOWN , UP , DOWN , UP});
    allStratagems.insert({super_earth_flag.getName(), super_earth_flag});
    
	Stratagem supply_pack("Supply Pack", {DOWN , LEFT , DOWN , UP , UP , DOWN});
    allStratagems.insert({supply_pack.getName(), supply_pack});
    
	Stratagem tesla_tower("Tesla Tower", {DOWN , UP , RIGHT , UP , LEFT , RIGHT});
    allStratagems.insert({tesla_tower.getName(), tesla_tower});

}

StratagemModel::~StratagemModel()
{
}