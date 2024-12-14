#include "LandingZones.h"
#define Logstd(Message) std::cout << Message << std::endl;
const std::vector<std::string> landingZones = {
          R"({point=Vector3(-289.80,346.69,269.68),startPoint=Vector3(-289.80,346.69,269.68),routeId="lz_drp_enemyBase_N0000|rt_drp_enemyBase_N_0000"})",
          R"({point=Vector3(802.56,345.37,1637.75),startPoint=Vector3(802.56,345.37,1637.75),routeId="lz_drp_field_N0000|rt_drp_field_N_0000"})",
          R"({point=Vector3(-351.61,321.89,768.34),startPoint=Vector3(-351.61,321.89,768.34),routeId="lz_drp_enemyBase_S0000|rt_drp_enemyBase_S_0000"})",
          R"({point=Vector3(-1663.71,536.63,-2201.78),startPoint=Vector3(-1663.71,536.63,-2201.78),routeId="lz_drp_citadelSouth_S0000|rt_drp_citadelSouth_S_0000"})",
          R"({point=Vector3(1651.17,353.38,587.98),startPoint=Vector3(1651.17,353.38,587.98),routeId="lz_drp_commFacility_S0000|rt_drp_commFacility_S_0000"})",
          R"({point=Vector3(834.42,451.21,-1420.10),startPoint=Vector3(834.42,451.21,-1420.10),routeId="lz_drp_cliffTown_N0000|rt_drp_clifftown_N_0000"})",
          R"({point=Vector3(-1718.06,474.38,-1713.62),startPoint=Vector3(-1718.06,474.38,-1713.62),routeId="lz_drp_sovietBase_N0000|rt_drp_sovietBase_N_0000"})",
          R"({point=Vector3(64.77,434.32,-842.65),startPoint=Vector3(64.77,434.32,-842.65),routeId="lz_drp_cliffTownWest_S0000|rt_drp_cliffTownWest_S_0000"})",
          R"({point=Vector3(-359.62,283.42,1714.79),startPoint=Vector3(-359.62,283.42,1714.79),routeId="lz_drp_field_W0000|rt_drp_field_W_0000"})",
          R"({point=Vector3(418.33,278.22,2261.37),startPoint=Vector3(418.33,278.22,2261.37),routeId="lz_drp_field_I0000|rt_drp_field_I_0000"})",
          R"({point=Vector3(-836.84,288.90,1574.03),startPoint=Vector3(-836.84,288.90,1574.03),routeId="lz_drp_remnantsNorth_N0000|rt_drp_remnantsNorth_N_0000"})",
          R"({point=Vector3(2305.28,394.03,-923.73),startPoint=Vector3(2305.28,394.03,-923.73),routeId="lz_drp_fort_E0000|rt_drp_fort_E_0000"})",
          R"({point=Vector3(1187.73,320.98,-10.40),startPoint=Vector3(1187.73,320.98,-10.40),routeId="lz_drp_slopedTownEast_E0000|rt_drp_slopedTownEast_E_0000"})",
          R"({point=Vector3(1444.40,364.14,390.78),startPoint=Vector3(1444.40,364.14,390.78),routeId="lz_drp_commFacility_I0000|rt_drp_commFacility_I_0000"})",
          R"({point=Vector3(-1677.59,360.88,-321.82),startPoint=Vector3(-1677.59,360.88,-321.82),routeId="lz_drp_waterway_I0000|rt_drp_waterway_I_0000"})",
          R"({point=Vector3(-1949.57,439.73,-1170.39),startPoint=Vector3(-1949.57,439.73,-1170.39),routeId="lz_drp_sovietBase_S0000|rt_drp_sovietBase_S_0000"})",
          R"({point=Vector3(-630.25,444.69,-910.73),startPoint=Vector3(-630.25,444.69,-910.73),routeId="lz_drp_powerPlant_S0000|rt_drp_powerPlant_S_0000"})",
          R"({point=Vector3(1904.32,368.36,81.33),startPoint=Vector3(1904.32,368.36,81.33),routeId="lz_drp_bridge_S0000|rt_drp_bridge_S_0000"})",
          R"({point=Vector3(141.47,275.51,2353.44),startPoint=Vector3(141.47,275.51,2353.44),routeId="lz_drp_fieldWest_S0000|rt_drp_fiieldWest_S_0000"})",
          R"({point=Vector3(-424.83,289.10,2004.96),startPoint=Vector3(-424.83,289.10,2004.96),routeId="lz_drp_remnants_S0000|rt_drp_remnants_S_0000"})",
          R"({point=Vector3(822.37,360.44,292.44),startPoint=Vector3(822.37,360.44,292.44),routeId="lz_drp_slopedTown_E0000|rt_drp_slopedTown_E_0000"})",
          R"({point=Vector3(1275.22,337.42,1313.33),startPoint=Vector3(1275.22,337.42,1313.33),routeId="lz_drp_ruinsNorth_S0000|rt_drp_ruinsNorth_S_0000"})",
          R"({point=Vector3(512.11,316.60,167.44),startPoint=Vector3(512.11,316.60,167.44),routeId="lz_drp_slopedTown_I0000|rt_drp_slopedTown_I_0000"})",
          R"({point=Vector3(2106.16,463.64,-1747.21),startPoint=Vector3(2106.16,463.64,-1747.21),routeId="lz_drp_fort_I0000|rt_drp_fort_I_0000"})",
          R"({point=Vector3(-1761.73,317.69,806.51),startPoint=Vector3(-1761.73,317.69,806.51),routeId="lz_drp_tent_I0000|rt_drp_tent_I_0000"})",
          R"({point=Vector3(20.70,329.63,888.03),startPoint=Vector3(20.70,329.63,888.03),routeId="lz_drp_village_W0000|rt_drp_village_W_0000"})",
          R"({point=Vector3(-1273.30,305.48,1342.07),startPoint=Vector3(-1273.30,305.48,1342.07),routeId="lz_drp_remnantsNorth_S0000|rt_drp_remnantsNorth_S_0000"})",
          R"({point=Vector3(612.73,355.48,911.22),startPoint=Vector3(612.73,355.48,911.22),routeId="lz_drp_village_N0000|rt_drp_village_N_0000"})",
          R"({point=Vector3(-1868.78,338.48,538.78),startPoint=Vector3(-1868.78,338.48,538.78),routeId="lz_drp_tent_N0000|rt_drp_tent_N_0000"})",
          R"({point=Vector3(-1372.18,318.33,934.68),startPoint=Vector3(-1372.18,318.33,934.68),routeId="lz_drp_tent_E0000|rt_drp_tent_E_0000"})",
          R"({point=Vector3(95.31,320.37,243.91),startPoint=Vector3(95.31,320.37,243.91),routeId="lz_drp_slopedTown_W0000|rt_drp_slopedTown_W_0000"})",
          R"({point=Vector3(-805.54,291.88,1820.65),startPoint=Vector3(-805.54,291.88,1820.65),routeId="lz_drp_remnants_I0000|rt_drp_remnants_I_0000"})",
          R"({point=Vector3(1649.11,491.21,-1340.58),startPoint=Vector3(1649.11,491.21,-1340.58),routeId="lz_drp_fort_W0000|rt_drp_fort_W_0000"})",
          R"({point=Vector3(1060.06,362.05,467.90),startPoint=Vector3(1060.06,362.05,467.90),routeId="lz_drp_commFacility_W0000|rt_drp_commFacility_W_0000"})",
          R"({point=Vector3(759.83,452.30,-1113.10),startPoint=Vector3(759.83,452.30,-1113.10),routeId="lz_drp_cliffTown_I0000|rt_drp_cliffTown_I0000"})",
          R"({point=Vector3(-662.20,556.88,-1489.06),startPoint=Vector3(-662.20,556.88,-1489.06),routeId="lz_drp_powerPlant_E0000|rt_drp_powerPlant_E_0000"})",
          R"({point=Vector3(491.46,418.47,-693.19),startPoint=Vector3(491.46,418.47,-693.19),routeId="lz_drp_cliffTown_S0000|rt_drp_cliffTown_S_0000"})",
          R"({point=Vector3(-596.89,353.02,497.40),startPoint=Vector3(-596.89,353.02,497.40),routeId="lz_drp_enemyBase_I0000|rt_drp_enemyBase_I_0000"})",
          R"({point=Vector3(1272.20,329.63,1853.51),startPoint=Vector3(1272.20,329.63,1853.51),routeId="lz_drp_ruins_S0000|rt_drp_ruins_S_0000"})",
          R"({point=Vector3(-2355.80,445.52,-1431.61),startPoint=Vector3(-2355.80,445.52,-1431.61),routeId="lz_drp_sovietBase_E0000|rt_drp_sovietBase_E_0000"})",
          R"({point=Vector3(-1219.28,416.14,-886.41),startPoint=Vector3(-1219.28,416.14,-886.41),routeId="lz_drp_sovietSouth_S0000|rt_drp_sovietSouth_S_0000"})",
          R"({point=Vector3(2331.11,208.01,-2487.00),startPoint=Vector3(2331.11,208.01,-2487.00),routeId="lz_drp_lab_W0000|rt_drp_lab_W_0000"})",
          R"({point=Vector3(2154.83,63.09,366.70),startPoint=Vector3(2154.83,63.09,366.70),routeId="lz_drp_hill_I0000|rt_drp_hill_I_0000"})",
          R"({point=Vector3(1096.40,150.86,-1685.39),startPoint=Vector3(1096.40,150.86,-1685.39),routeId="lz_drp_diamond_N0000|rt_drp_diamond_N_0000"})",
          R"({point=Vector3(-163.59,7.96,385.58),startPoint=Vector3(-163.59,7.96,385.58),routeId="lz_drp_swamp_S0000|rt_drp_swamp_S_0000"})",
          R"({point=Vector3(510.10,20.43,-732.55),startPoint=Vector3(510.10,20.43,-732.55),routeId="lz_drp_savannahWest_N0000|lz_drp_savannahWest_N_0000"})",
          R"({point=Vector3(924.72,44.01,-931.28),startPoint=Vector3(924.72,44.01,-931.28),routeId="lz_drp_diamondWest_S0000|lz_drp_diamondWest_S_0000"})",
          R"({point=Vector3(-19.63,11.17,140.91),startPoint=Vector3(-19.63,11.17,140.91),routeId="lz_drp_swamp_I0000|rt_drp_swamp_I_0000"})",
          R"({point=Vector3(846.46,-4.97,1148.62),startPoint=Vector3(846.46,-4.97,1148.62),routeId="lz_drp_pfCamp_I0000|rt_drp_pfCamp_I_0000"})",
          R"({point=Vector3(1014.25,57.18,-221.46),startPoint=Vector3(1014.25,57.18,-221.46),routeId="lz_drp_savannah_I0000|rt_drp_savannah_I_0000"})",
          R"({point=Vector3(1061.84,6.78,731.21),startPoint=Vector3(1061.84,6.78,731.21),routeId="lz_drp_pfCamp_N0000|rt_drp_pfcamp_N_0000"})",
          R"({point=Vector3(1381.85,137.05,-1516.01),startPoint=Vector3(1381.85,137.05,-1516.01),routeId="lz_drp_diamond_I0000|rt_drp_diamond_I_0000"})",
          R"({point=Vector3(1203.80,107.74,-792.16),startPoint=Vector3(1203.80,107.74,-792.16),routeId="lz_drp_diamondSouth_W0000|rt_drp_diamondSouth_W_0000"})",
          R"({point=Vector3(2271.82,84.84,-418.59),startPoint=Vector3(2271.82,84.84,-418.59),routeId="lz_drp_factoryWest_S0000|lz_drp_factoryWest_S_0000"})",
          R"({point=Vector3(1007.02,-4.46,1557.61),startPoint=Vector3(1007.02,-4.46,1557.61),routeId="lz_drp_pfCamp_S0000|lz_drp_pfCamp_S_0000"})",
          R"({point=Vector3(-145.52,16.15,-379.20),startPoint=Vector3(-145.52,16.15,-379.20),routeId="lz_drp_swamp_N0000|lz_drp_swamp_N_0000"})",
          R"({point=Vector3(1786.78,170.73,-2130.50),startPoint=Vector3(1786.78,170.73,-2130.50),routeId="lz_drp_labWest_W0000|rt_drp_labWest_W_0000"})",
          R"({point=Vector3(2521.90,111.82,-1833.82),startPoint=Vector3(2521.90,111.82,-1833.82),routeId="lz_drp_lab_S0000|rt_drp_lab_S_0000"})",
          R"({point=Vector3(1119.97,10.72,317.63),startPoint=Vector3(1119.97,10.72,317.63),routeId="lz_drp_savannahEast_S0000|lz_drp_savannahEast_S_0000"})",
          R"({point=Vector3(1769.46,28.60,560.59),startPoint=Vector3(1769.46,28.60,560.59),routeId="lz_drp_hillWest_S0000|lz_drp_hillWest_S_0000"})",
          R"({point=Vector3(1951.46,49.82,88.58),startPoint=Vector3(1951.46,49.82,88.58),routeId="lz_drp_hill_N0000|lz_drp_hill_N_0000"})",
          R"({point=Vector3(582.54,-3.14,418.17),startPoint=Vector3(582.54,-3.14,418.17),routeId="lz_drp_pfCampNorth_S0000|rt_drp_pfCampNorth_S_0000"})",
          R"({point=Vector3(-618.09,6.48,232.79),startPoint=Vector3(-618.09,6.48,232.79),routeId="lz_drp_swamp_W0000|lz_drp_swamp_W_0000"})",
          R"({point=Vector3(74.70,18.20,-689.41),startPoint=Vector3(74.70,18.20,-689.41),routeId="lz_drp_bananaSouth_N0000|rt_drp_bananaSouth_N_0000"})",
          R"({point=Vector3(266.57,1.56,-234.08),startPoint=Vector3(266.57,1.56,-234.08),routeId="lz_drp_swampEast_N0000|lz_drp_swampEast_N_0000"})",
          R"({point=Vector3(1648.35,87.11,-555.26),startPoint=Vector3(1648.35,87.11,-555.26),routeId="lz_drp_diamondSouth_S0000|lz_drp_diamondSouth_S_0000"})",
          R"({point=Vector3(1688.90,-3.65,1520.55),startPoint=Vector3(1688.90,-3.65,1520.55),routeId="lz_drp_hillSouth_W0000|lz_drp_hillSouth_W_0000"})",
          R"({point=Vector3(300.61,50.06,-1237.66),startPoint=Vector3(300.61,50.06,-1237.66),routeId="lz_drp_banana_I0000|rt_drp_banana_I_0000"})",
          R"({point=Vector3(2465.21,71.47,230.49),startPoint=Vector3(2465.21,71.47,230.49),routeId="lz_drp_hill_E0000|lz_drp_hill_E_0000"})",
          R"({point=Vector3(2441.72,78.25,-1191.68),startPoint=Vector3(2441.72,78.25,-1191.68),routeId="lz_drp_factory_N0000|rt_drp_factory_N_0000"})",
          R"({point=Vector3(1233.17,25.84,-127.05),startPoint=Vector3(1233.17,25.84,-127.05),routeId="lz_drp_savannahEast_N0000|rt_drp_savannahEast_N_0000"})",
          R"({point=Vector3(-610.26,13.10,-398.20),startPoint=Vector3(-610.26,13.10,-398.20),routeId="lz_drp_flowStation_E0000|lz_drp_flowStation_E_0000"})",
          R"({point=Vector3(-1001.38,-7.20,-199.16),startPoint=Vector3(-1001.38,-7.20,-199.16),routeId="lz_drp_flowStation_I0000|rt_drp_flowStation_I_0000"})",
          R"({point=Vector3(-440.57,-14.39,1339.17),startPoint=Vector3(-440.57,-14.39,1339.17),routeId="lz_drp_outland_S0000|rt_drp_outland_S_0000"})",
};


// Function to split a string into a vector based on a delimiter
std::vector<std::string> SplitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(str);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
std::vector<std::string> checkedLZsVector;
std::vector<std::string> allRouteId;
// Function to filter and format landing zones
std::string GetListLandingZone(const std::string& checkedLZs) {
    
    std::ostringstream result;
    checkedLZsVector = SplitString(checkedLZs, '\n'); // Split by newlines
    allRouteId = checkedLZsVector;
    // Loop through the list of all landing zones
    for (const auto& lz : landingZones) {
        for (const auto& checkedLZ : checkedLZsVector) {
            // If the checked landing zone is found in the current zone
            if (lz.find(checkedLZ) != std::string::npos) {
                result << "            {\n"
                    << "                " << lz.substr(1, lz.size() - 2) << "\n"
                    << "            },\n";
            }
        }
    }
    std::cout << result.str() << std::endl;
    getUsedHeliRoutes();
    return result.str();
}

std::string getUsedHeliRoutes() {
    std::string s;

    for (const auto& route : allRouteId) {
        s += "		\"" + route + "|" + route + "\",\n";
    }
#ifdef _DEBUG
    Logstd("Routes: " + s);
#endif // _DEBUG

    return s;
}