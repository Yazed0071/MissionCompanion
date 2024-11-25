#include "LandingZones.h"

const std::vector<std::string> landingZones = {
          R"({point=Vector3(-289.80,346.69,269.68),startPoint=Vector3(161.28,335.69,140.48),routeId="lz_drp_enemyBase_N0000|rt_drp_enemyBase_N_0000"})",
          R"({point=Vector3(802.56,345.37,1637.75),startPoint=Vector3(1247.97,345.37,1298.36),routeId="lz_drp_field_N0000|rt_drp_field_N_0000"})",
          R"({point=Vector3(-351.61,321.89,768.34),startPoint=Vector3(-91.82,331.89,918.56),routeId="lz_drp_enemyBase_S0000|rt_drp_enemyBase_S_0000"})",
          R"({point=Vector3(-1663.71,536.63,-2201.78),startPoint=Vector3(-1531.39,474.63,-1679.84),routeId="lz_drp_citadelSouth_S0000|rt_drp_citadelSouth_S_0000"})",
          R"({point=Vector3(1651.17,353.38,587.98),startPoint=Vector3(1701.22,353.38,1084.22),routeId="lz_drp_commFacility_S0000|rt_drp_commFacility_S_0000"})",
          R"({point=Vector3(834.42,451.21,-1420.10),startPoint=Vector3(1398.39,514.21,-1245.88),routeId="lz_drp_cliffTown_N0000|rt_drp_clifftown_N_0000"})",
          R"({point=Vector3(-1718.06,474.38,-1713.62),startPoint=Vector3(-1590.27,526.60,-2075.17),routeId="lz_drp_sovietBase_N0000|rt_drp_sovietBase_N_0000"})",
          R"({point=Vector3(64.77,434.32,-842.65),startPoint=Vector3(462.40,432.32,-727.01),routeId="lz_drp_cliffTownWest_S0000|rt_drp_cliffTownWest_S_0000"})",
          R"({point=Vector3(-359.62,283.42,1714.79),startPoint=Vector3(-771.13,305.42,1447.29),routeId="lz_drp_field_W0000|rt_drp_field_W_0000"})",
          R"({point=Vector3(418.33,278.22,2261.37),startPoint=Vector3(887.95,309.12,2383.44),routeId="lz_drp_field_I0000|rt_drp_field_I_0000"})",
          R"({point=Vector3(-836.84,288.90,1574.03),startPoint=Vector3(-312.47,306.90,1792.76),routeId="lz_drp_remnantsNorth_N0000|rt_drp_remnantsNorth_N_0000"})",
          R"({point=Vector3(2305.28,394.03,-923.73),startPoint=Vector3(2636.58,397.03,-805.06),routeId="lz_drp_fort_E0000|rt_drp_fort_E_0000"})",
          R"({point=Vector3(1187.73,320.98,-10.40),startPoint=Vector3(1489.55,336.98,65.91),routeId="lz_drp_slopedTownEast_E0000|rt_drp_slopedTownEast_E_0000"})",
          R"({point=Vector3(1444.40,364.14,390.78),startPoint=Vector3(925.92,368.14,502.51),routeId="lz_drp_commFacility_I0000|rt_drp_commFacility_I_0000"})",
          R"({point=Vector3(-1677.59,360.88,-321.82),startPoint=Vector3(-1861.11,373.88,-136.02),routeId="lz_drp_waterway_I0000|rt_drp_waterway_I_0000"})",
          R"({point=Vector3(-1949.57,439.73,-1170.39),startPoint=Vector3(-1441.68,439.73,-1006.99),routeId="lz_drp_sovietBase_S0000|rt_drp_sovietBase_S_0000"})",
          R"({point=Vector3(-630.25,444.69,-910.73),startPoint=Vector3(-400.84,502.69,-1175.87),routeId="lz_drp_powerPlant_S0000|rt_drp_powerPlant_S_0000"})",
          R"({point=Vector3(1904.32,368.36,81.33),startPoint=Vector3(1340.73,356.36,44.81),routeId="lz_drp_bridge_S0000|rt_drp_bridge_S_0000"})",
          R"({point=Vector3(141.47,275.51,2353.44),startPoint=Vector3(-249.77,310.51,1998.40),routeId="lz_drp_fieldWest_S0000|rt_drp_fiieldWest_S_0000"})",
          R"({point=Vector3(-424.83,289.10,2004.96),startPoint=Vector3(54.07,312.10,2230.84),routeId="lz_drp_remnants_S0000|rt_drp_remnants_S_0000"})",
          R"({point=Vector3(822.37,360.44,292.44),startPoint=Vector3(335.25,364.44,413.83),routeId="lz_drp_slopedTown_E0000|rt_drp_slopedTown_E_0000"})",
          R"({point=Vector3(1275.22,337.42,1313.33),startPoint=Vector3(1255.64,340.42,1747.07),routeId="lz_drp_ruinsNorth_S0000|rt_drp_ruinsNorth_S_0000"})",
          R"({point=Vector3(512.11,316.60,167.44),startPoint=Vector3(1074.92,379.60,506.01),routeId="lz_drp_slopedTown_I0000|rt_drp_slopedTown_I_0000"})",
          R"({point=Vector3(2106.16,463.64,-1747.21),startPoint=Vector3(2043.26,474.64,-1248.49),routeId="lz_drp_fort_I0000|rt_drp_fort_I_0000"})",
          R"({point=Vector3(-1761.73,317.69,806.51),startPoint=Vector3(-1158.50,335.69,1422.75),routeId="lz_drp_tent_I0000|rt_drp_tent_I_0000"})",
          R"({point=Vector3(20.70,329.63,888.03),startPoint=Vector3(626.34,354.63,849.22),routeId="lz_drp_village_W0000|rt_drp_village_W_0000"})",
          R"({point=Vector3(-1273.30,305.48,1342.07),startPoint=Vector3(-887.87,311.48,1427.74),routeId="lz_drp_remnantsNorth_S0000|rt_drp_remnantsNorth_S_0000"})",
          R"({point=Vector3(612.73,355.48,911.22),startPoint=Vector3(2.37,343.48,848.51),routeId="lz_drp_village_N0000|rt_drp_village_N_0000"})",
          R"({point=Vector3(-1868.78,338.48,538.78),startPoint=Vector3(-1886.95,348.98,166.98),routeId="lz_drp_tent_N0000|rt_drp_tent_N_0000"})",
          R"({point=Vector3(-1372.18,318.33,934.68),startPoint=Vector3(-1183.10,332.33,1243.43),routeId="lz_drp_tent_E0000|rt_drp_tent_E_0000"})",
          R"({point=Vector3(95.31,320.37,243.91),startPoint=Vector3(-454.10,368.37,206.70),routeId="lz_drp_slopedTown_W0000|rt_drp_slopedTown_W_0000"})",
          R"({point=Vector3(-805.54,291.88,1820.65),startPoint=Vector3(-248.03,297.88,1963.33),routeId="lz_drp_remnants_I0000|rt_drp_remnants_I_0000"})",
          R"({point=Vector3(1649.11,491.21,-1340.58),startPoint=Vector3(1034.49,511.21,-1286.79),routeId="lz_drp_fort_W0000|rt_drp_fort_W_0000"})",
          R"({point=Vector3(1060.06,362.05,467.90),startPoint=Vector3(590.77,374.89,368.06),routeId="lz_drp_commFacility_W0000|rt_drp_commFacility_W_0000"})",
          R"({point=Vector3(759.83,452.30,-1113.10),startPoint=Vector3(65.71,437.30,-792.83),routeId="lz_drp_cliffTown_I0000|rt_drp_cliffTown_I0000"})",
          R"({point=Vector3(-662.20,556.88,-1489.06),startPoint=Vector3(-433.13,522.23,-1094.86),routeId="lz_drp_powerPlant_E0000|rt_drp_powerPlant_E_0000"})",
          R"({point=Vector3(491.46,418.47,-693.19),startPoint=Vector3(886.63,393.47,-299.32),routeId="lz_drp_cliffTown_S0000|rt_drp_cliffTown_S_0000"})",
          R"({point=Vector3(-596.89,353.02,497.40),startPoint=Vector3(-946.28,309.02,981.35),routeId="lz_drp_enemyBase_I0000|rt_drp_enemyBase_I_0000"})",
          R"({point=Vector3(1272.20,329.63,1853.51),startPoint=Vector3(1250.48,317.63,2167.53),routeId="lz_drp_ruins_S0000|rt_drp_ruins_S_0000"})",
          R"({point=Vector3(-2355.80,445.52,-1431.61),startPoint=Vector3(-1639.10,466.52,-1589.67),routeId="lz_drp_sovietBase_E0000|rt_drp_sovietBase_E_0000"})",
          R"({point=Vector3(-1219.28,416.14,-886.41),startPoint=Vector3(-583.54,445.14,-815.04),routeId="lz_drp_sovietSouth_S0000|rt_drp_sovietSouth_S_0000"})",
          R"({point=Vector3(2331.11,208.01,-2487.00),startPoint=Vector3(2069.32,209.01,-2087.33),routeId="lz_drp_lab_W0000|rt_drp_lab_W_0000"})",
          R"({point=Vector3(2154.83,63.09,366.70),startPoint=Vector3(1472.96,56.09,535.65),routeId="lz_drp_hill_I0000|rt_drp_hill_I_0000"})",
          R"({point=Vector3(1096.40,150.86,-1685.39),startPoint=Vector3(1145.97,148.86,-1044.72),routeId="lz_drp_diamond_N0000|rt_drp_diamond_N_0000"})",
          R"({point=Vector3(-163.59,7.96,385.58),startPoint=Vector3(129.00,40.96,832.24),routeId="lz_drp_swamp_S0000|rt_drp_swamp_S_0000"})",
          R"({point=Vector3(510.10,20.43,-732.55),startPoint=Vector3(430.71,35.43,-208.19),routeId="lz_drp_savannahWest_N0000|lz_drp_savannahWest_N_0000"})",
          R"({point=Vector3(924.72,44.01,-931.28),startPoint=Vector3(1280.06,60.93,-437.63),routeId="lz_drp_diamondWest_S0000|lz_drp_diamondWest_S_0000"})",
          R"({point=Vector3(-19.63,11.17,140.91),startPoint=Vector3(-690.06,9.17,384.74),routeId="lz_drp_swamp_I0000|rt_drp_swamp_I_0000"})",
          R"({point=Vector3(846.46,-4.97,1148.62),startPoint=Vector3(1340.72,3.13,1707.16),routeId="lz_drp_pfCamp_I0000|rt_drp_pfCamp_I_0000"})",
          R"({point=Vector3(1014.25,57.18,-221.46),startPoint=Vector3(263.05,40.18,-292.45),routeId="lz_drp_savannah_I0000|rt_drp_savannah_I_0000"})",
          R"({point=Vector3(1061.84,6.78,731.21),startPoint=Vector3(625.74,29.78,306.26),routeId="lz_drp_pfCamp_N0000|rt_drp_pfcamp_N_0000"})",
          R"({point=Vector3(1381.85,137.05,-1516.01),startPoint=Vector3(1083.13,158.05,-1892.86),routeId="lz_drp_diamond_I0000|rt_drp_diamond_I_0000"})",
          R"({point=Vector3(1203.80,107.74,-792.16),startPoint=Vector3(1225.37,122.74,-303.61),routeId="lz_drp_diamondSouth_W0000|rt_drp_diamondSouth_W_0000"})",
          R"({point=Vector3(2271.82,84.84,-418.59),startPoint=Vector3(2416.57,86.54,-33.38),routeId="lz_drp_factoryWest_S0000|lz_drp_factoryWest_S_0000"})",
          R"({point=Vector3(1007.02,-4.46,1557.61),startPoint=Vector3(1580.16,18.96,1490.89),routeId="lz_drp_pfCamp_S0000|lz_drp_pfCamp_S_0000"})",
          R"({point=Vector3(-145.52,16.15,-379.20),startPoint=Vector3(474.18,30.15,-323.11),routeId="lz_drp_swamp_N0000|lz_drp_swamp_N_0000"})",
          R"({point=Vector3(1786.78,170.73,-2130.50),startPoint=Vector3(1623.44,168.73,-1806.87),routeId="lz_drp_labWest_W0000|rt_drp_labWest_W_0000"})",
          R"({point=Vector3(2521.90,111.82,-1833.82),startPoint=Vector3(2481.70,86.82,-1321.02),routeId="lz_drp_lab_S0000|rt_drp_lab_S_0000"})",
          R"({point=Vector3(1119.97,10.72,317.63),startPoint=Vector3(564.28,31.72,31.20),routeId="lz_drp_savannahEast_S0000|lz_drp_savannahEast_S_0000"})",
          R"({point=Vector3(1769.46,28.60,560.59),startPoint=Vector3(1318.61,56.60,247.85),routeId="lz_drp_hillWest_S0000|lz_drp_hillWest_S_0000"})",
          R"({point=Vector3(1951.46,49.82,88.58),startPoint=Vector3(1644.07,67.82,633.63),routeId="lz_drp_hill_N0000|lz_drp_hill_N_0000"})",
          R"({point=Vector3(582.54,-3.14,418.17),startPoint=Vector3(416.04,37.87,955.68),routeId="lz_drp_pfCampNorth_S0000|rt_drp_pfCampNorth_S_0000"})",
          R"({point=Vector3(-618.09,6.48,232.79),startPoint=Vector3(-1170.26,39.73,167.57),routeId="lz_drp_swamp_W0000|lz_drp_swamp_W_0000"})",
          R"({point=Vector3(74.70,18.20,-689.41),startPoint=Vector3(430.19,36.20,-164.65),routeId="lz_drp_bananaSouth_N0000|rt_drp_bananaSouth_N_0000"})",
          R"({point=Vector3(266.57,1.56,-234.08),startPoint=Vector3(744.40,33.56,86.60),routeId="lz_drp_swampEast_N0000|lz_drp_swampEast_N_0000"})",
          R"({point=Vector3(1648.35,87.11,-555.26),startPoint=Vector3(1447.82,64.11,63.98),routeId="lz_drp_diamondSouth_S0000|lz_drp_diamondSouth_S_0000"})",
          R"({point=Vector3(1688.90,-3.65,1520.55),startPoint=Vector3(1910.28,19.35,1883.37),routeId="lz_drp_hillSouth_W0000|lz_drp_hillSouth_W_0000"})",
          R"({point=Vector3(300.61,50.06,-1237.66),startPoint=Vector3(559.74,38.06,-707.21),routeId="lz_drp_banana_I0000|rt_drp_banana_I_0000"})",
          R"({point=Vector3(2465.21,71.47,230.49),startPoint=Vector3(2447.80,89.47,-244.96),routeId="lz_drp_hill_E0000|lz_drp_hill_E_0000"})",
          R"({point=Vector3(2441.72,78.25,-1191.68),startPoint=Vector3(2678.54,97.25,-1790.59),routeId="lz_drp_factory_N0000|rt_drp_factory_N_0000"})",
          R"({point=Vector3(1233.17,25.84,-127.05),startPoint=Vector3(1836.30,103.84,5.63),routeId="lz_drp_savannahEast_N0000|rt_drp_savannahEast_N_0000"})",
          R"({point=Vector3(-610.26,13.10,-398.20),startPoint=Vector3(-513.43,36.10,39.07),routeId="lz_drp_flowStation_E0000|lz_drp_flowStation_E_0000"})",
          R"({point=Vector3(-1001.38,-7.20,-199.16),startPoint=Vector3(-853.18,22.80,251.66),routeId="lz_drp_flowStation_I0000|rt_drp_flowStation_I_0000"})",
          R"({point=Vector3(-440.57,-14.39,1339.17),startPoint=Vector3(-462.44,-5.39,1926.48),routeId="lz_drp_outland_S0000|rt_drp_outland_S_0000"})",
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

// Function to filter and format landing zones
std::string GetListLandingZone(const std::string& checkedLZs) {
    std::ostringstream result;
    std::vector<std::string> checkedLZsVector = SplitString(checkedLZs, '\n'); // Split by newlines

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

    return result.str();
}