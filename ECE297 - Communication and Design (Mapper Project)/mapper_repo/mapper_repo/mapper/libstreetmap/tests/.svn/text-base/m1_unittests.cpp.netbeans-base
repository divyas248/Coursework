#include <algorithm>
#include <random>
#include <unittest++/UnitTest++.h>
#include "unit_test_util.h"
#include "m1.h"

struct Map_Fixture {
	Map_Fixture() {
		//RNG Setup
		rng = std::minstd_rand(0);
		rand_intersection = std::uniform_int_distribution<unsigned>(0,getNumberOfIntersections()-1);
		rand_street = std::uniform_int_distribution<unsigned>(0,getNumberOfStreets()-1);
		rand_segment = std::uniform_int_distribution<unsigned>(0,getNumberOfStreetSegments()-1);
	}
	~Map_Fixture() {
	}
	std::minstd_rand rng;
	std::uniform_int_distribution<unsigned> rand_intersection;
	std::uniform_int_distribution<unsigned> rand_street;
	std::uniform_int_distribution<unsigned> rand_segment;
};

SUITE(M1_Public_Functionality_Tests) {
	TEST_FIXTURE(Map_Fixture, intersection_name_functionality) {
		CHECK_EQUAL(1648, find_intersection_id_from_name("Yonge Street & Eglinton Avenue East & Eglinton Avenue West"));
		CHECK_EQUAL(23162, find_intersection_id_from_name("Bay Street & Dundas Street West"));
		CHECK_EQUAL(58114, find_intersection_id_from_name("Bay Street & Wellington Street West"));
		CHECK_EQUAL(2298, find_intersection_id_from_name("Yonge Street & Dundas Street West & Dundas Street East"));
		CHECK_EQUAL(3023, find_intersection_id_from_name("Yonge Street & College Street & Carlton Street"));
		CHECK_EQUAL(2522, find_intersection_id_from_name("Yonge Street & Queen Street West & Queen Street East"));
		CHECK_EQUAL(40201, find_intersection_id_from_name("Bay Street & Adelaide Street West"));
		CHECK_EQUAL(10538, find_intersection_id_from_name("Yonge Street & King Street West & King Street East"));
		CHECK_EQUAL(1896, find_intersection_id_from_name("Yonge Street & Bloor Street East & Bloor Street West"));
		CHECK_EQUAL(27814, find_intersection_id_from_name("Bloor Street West & Bay Street"));
		CHECK_EQUAL(659, find_intersection_id_from_name("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West"));
		CHECK_EQUAL(9555, find_intersection_id_from_name("University Avenue & Front Street West & York Street"));
		CHECK_EQUAL(2972, find_intersection_id_from_name("Yonge Street & Adelaide Street West & Adelaide Street East"));
		CHECK_EQUAL(3482, find_intersection_id_from_name("Yonge Street & Gerrard Street West & Gerrard Street East"));
		CHECK_EQUAL(1851, find_intersection_id_from_name("Bloor Street East & Church Street"));
		CHECK_EQUAL(58107, find_intersection_id_from_name("King Street West & Bay Street"));
		CHECK_EQUAL(5438, find_intersection_id_from_name("University Avenue & Dundas Street West"));
		CHECK_EQUAL(1376, find_intersection_id_from_name("St. George Street & Harbord Street & Hoskin Avenue"));
		CHECK_EQUAL(5720, find_intersection_id_from_name("College Street & Bay Street"));
		CHECK_EQUAL(5600, find_intersection_id_from_name("Queen Street West & John Street"));
		CHECK_EQUAL(3369, find_intersection_id_from_name("Yonge Street & Wellesley Street East & Wellesley Street West"));
		CHECK_EQUAL(63371, find_intersection_id_from_name("Queen Street West & Bay Street"));
		CHECK_EQUAL(130357, find_intersection_id_from_name("Avenue Road & Bloor Street West & Queen's Park"));
		CHECK_EQUAL(5450, find_intersection_id_from_name("Front Street West & John Street & Convention centre loading dock"));
		CHECK_EQUAL(73004, find_intersection_id_from_name("University Avenue & Wellington Street West"));
	}

	TEST_FIXTURE(Map_Fixture, street_name_functionality) {
		CHECK_EQUAL(38, find_street_id_from_name("Yonge Street"));
		CHECK_EQUAL(180, find_street_id_from_name("Eglinton Avenue East"));
		CHECK_EQUAL(233, find_street_id_from_name("Bay Street"));
		CHECK_EQUAL(281, find_street_id_from_name("Dundas Street West"));
		CHECK_EQUAL(196, find_street_id_from_name("College Street"));
		CHECK_EQUAL(138, find_street_id_from_name("University Avenue"));
		CHECK_EQUAL(133, find_street_id_from_name("Bloor Street West"));
		CHECK_EQUAL(132, find_street_id_from_name("Danforth Avenue"));
		CHECK_EQUAL(194, find_street_id_from_name("Queen Street West"));
		CHECK_EQUAL(390, find_street_id_from_name("Queen Street East"));
		CHECK_EQUAL(13, find_street_id_from_name("Avenue Road"));
		CHECK_EQUAL(145, find_street_id_from_name("Bathurst Street"));
		CHECK_EQUAL(161, find_street_id_from_name("Dufferin Street"));
		CHECK_EQUAL(4018, find_street_id_from_name("Weston Road"));
		CHECK_EQUAL(69, find_street_id_from_name("Sheppard Avenue East"));
		CHECK_EQUAL(202, find_street_id_from_name("Finch Avenue West"));
		CHECK_EQUAL(185, find_street_id_from_name("Steeles Avenue East"));
		CHECK_EQUAL(433, find_street_id_from_name("William R. Allen Road"));
		CHECK_EQUAL(142, find_street_id_from_name("Lake Shore Boulevard West"));
		CHECK_EQUAL(4396, find_street_id_from_name("Erin Mills Parkway"));
		CHECK_EQUAL(2362, find_street_id_from_name("Morningside Avenue"));
		CHECK_EQUAL(683, find_street_id_from_name("McCowan Road"));
	}

	TEST_FIXTURE(Map_Fixture, intersection_name_street_segments_functionality) {
		std::vector<unsigned> result;
		std::vector<unsigned> expected_result;
		
		expected_result = {1376, 28919, 113281, 172708};
		result = find_intersection_street_segments("Yonge Street & Eglinton Avenue East & Eglinton Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {22411, 189079, 189082, 189083};
		result = find_intersection_street_segments("Bay Street & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {59599, 59600, 156997, 156998};
		result = find_intersection_street_segments("Bay Street & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1981, 39107, 64033, 189086};
		result = find_intersection_street_segments("Yonge Street & Dundas Street West & Dundas Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2574, 27023, 27024, 27026, 45769};
		result = find_intersection_street_segments("Yonge Street & College Street & Carlton Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2180, 51195, 51196, 51201};
		result = find_intersection_street_segments("Yonge Street & Queen Street West & Queen Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {39675, 59594, 65873, 117445};
		result = find_intersection_street_segments("Bay Street & Adelaide Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {9723, 59593, 117450, 117451};
		result = find_intersection_street_segments("Yonge Street & King Street West & King Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1589, 39082, 194517, 203781};
		result = find_intersection_street_segments("Yonge Street & Bloor Street East & Bloor Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {27028, 39180, 136567, 194512};
		result = find_intersection_street_segments("Bloor Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {550, 8440, 183655, 183656};
		result = find_intersection_street_segments("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {8706, 65874, 65876, 65878};
		result = find_intersection_street_segments("University Avenue & Front Street West & York Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2530, 117448, 117453, 117454};
		result = find_intersection_street_segments("Yonge Street & Adelaide Street West & Adelaide Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2996, 39113, 39959, 192111};
		result = find_intersection_street_segments("Yonge Street & Gerrard Street West & Gerrard Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1545, 132715, 189936, 213108};
		result = find_intersection_street_segments("Bloor Street East & Church Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {59589, 59590, 59596, 59597};
		result = find_intersection_street_segments("King Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4777, 134252, 189076, 189558};
		result = find_intersection_street_segments("University Avenue & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1130, 10815, 155458, 207003};
		result = find_intersection_street_segments("St. George Street & Harbord Street & Hoskin Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5037, 45764, 45765, 192957};
		result = find_intersection_street_segments("College Street & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4928, 4961, 159696, 159697};
		result = find_intersection_street_segments("Queen Street West & John Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2895, 115350, 203782, 203785};
		result = find_intersection_street_segments("Yonge Street & Wellesley Street East & Wellesley Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {65867, 134489, 134490, 193241};
		result = find_intersection_street_segments("Queen Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {154794, 154795, 198501, 198583};
		result = find_intersection_street_segments("Avenue Road & Bloor Street West & Queen's Park");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4788, 134526, 135191, 196837};
		result = find_intersection_street_segments("Front Street West & John Street & Convention centre loading dock");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {76719, 188360, 188368, 200060};
		result = find_intersection_street_segments("University Avenue & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, intersection_id_street_segments_functionality) {
		std::vector<unsigned> result;
		std::vector<unsigned> expected_result;
		
		expected_result = {1376, 28919, 113281, 172708};
		result = find_intersection_street_segments(1648);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {22411, 189079, 189082, 189083};
		result = find_intersection_street_segments(23162);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {59599, 59600, 156997, 156998};
		result = find_intersection_street_segments(58114);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1981, 39107, 64033, 189086};
		result = find_intersection_street_segments(2298);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2574, 27023, 27024, 27026, 45769};
		result = find_intersection_street_segments(3023);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2180, 51195, 51196, 51201};
		result = find_intersection_street_segments(2522);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {39675, 59594, 65873, 117445};
		result = find_intersection_street_segments(40201);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {9723, 59593, 117450, 117451};
		result = find_intersection_street_segments(10538);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1589, 39082, 194517, 203781};
		result = find_intersection_street_segments(1896);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {27028, 39180, 136567, 194512};
		result = find_intersection_street_segments(27814);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {550, 8440, 183655, 183656};
		result = find_intersection_street_segments(659);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {8706, 65874, 65876, 65878};
		result = find_intersection_street_segments(9555);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2530, 117448, 117453, 117454};
		result = find_intersection_street_segments(2972);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2996, 39113, 39959, 192111};
		result = find_intersection_street_segments(3482);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1545, 132715, 189936, 213108};
		result = find_intersection_street_segments(1851);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {59589, 59590, 59596, 59597};
		result = find_intersection_street_segments(58107);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4777, 134252, 189076, 189558};
		result = find_intersection_street_segments(5438);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1130, 10815, 155458, 207003};
		result = find_intersection_street_segments(1376);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5037, 45764, 45765, 192957};
		result = find_intersection_street_segments(5720);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4928, 4961, 159696, 159697};
		result = find_intersection_street_segments(5600);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2895, 115350, 203782, 203785};
		result = find_intersection_street_segments(3369);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {65867, 134489, 134490, 193241};
		result = find_intersection_street_segments(63371);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {154794, 154795, 198501, 198583};
		result = find_intersection_street_segments(130357);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4788, 134526, 135191, 196837};
		result = find_intersection_street_segments(5450);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {76719, 188360, 188368, 200060};
		result = find_intersection_street_segments(73004);
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, intersection_name_street_names_functionality) {
		std::vector<std::string> result;
		std::vector<std::string> expected_result;
		
		expected_result = {"Eglinton Avenue East", "Eglinton Avenue West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Eglinton Avenue East & Eglinton Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "Dundas Street West"};
		result = find_intersection_street_names("Bay Street & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "Wellington Street West"};
		result = find_intersection_street_names("Bay Street & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Dundas Street East", "Dundas Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Dundas Street West & Dundas Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Carlton Street", "College Street", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & College Street & Carlton Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Queen Street East", "Queen Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Queen Street West & Queen Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Adelaide Street West", "Bay Street"};
		result = find_intersection_street_names("Bay Street & Adelaide Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"King Street East", "King Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & King Street West & King Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bloor Street East", "Bloor Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Bloor Street East & Bloor Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "Bloor Street West"};
		result = find_intersection_street_names("Bloor Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Saint Clair Avenue East", "Saint Clair Avenue West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Front Street West", "University Avenue", "York Street"};
		result = find_intersection_street_names("University Avenue & Front Street West & York Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Adelaide Street East", "Adelaide Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Adelaide Street West & Adelaide Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Gerrard Street East", "Gerrard Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Gerrard Street West & Gerrard Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bloor Street East", "Church Street"};
		result = find_intersection_street_names("Bloor Street East & Church Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "King Street West"};
		result = find_intersection_street_names("King Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Dundas Street West", "University Avenue"};
		result = find_intersection_street_names("University Avenue & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Harbord Street", "Hoskin Avenue", "St. George Street"};
		result = find_intersection_street_names("St. George Street & Harbord Street & Hoskin Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "College Street"};
		result = find_intersection_street_names("College Street & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"John Street", "Queen Street West"};
		result = find_intersection_street_names("Queen Street West & John Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Wellesley Street East", "Wellesley Street West", "Yonge Street"};
		result = find_intersection_street_names("Yonge Street & Wellesley Street East & Wellesley Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Bay Street", "Queen Street West"};
		result = find_intersection_street_names("Queen Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Avenue Road", "Bloor Street West", "Queen's Park"};
		result = find_intersection_street_names("Avenue Road & Bloor Street West & Queen's Park");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"Convention centre loading dock", "Front Street West", "John Street"};
		result = find_intersection_street_names("Front Street West & John Street & Convention centre loading dock");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {"University Avenue", "Wellington Street West"};
		result = find_intersection_street_names("University Avenue & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, directly_connected_functionality) {
		//Intersections that should be directly connected
		CHECK(are_directly_connected("Yonge Street & Eglinton Avenue East & Eglinton Avenue West", "Yonge Street & Eglinton Avenue East & Eglinton Avenue West"));
		CHECK(are_directly_connected("University Avenue (35)", "University Avenue & Dundas Street West"));
		CHECK(are_directly_connected("Yonge Street & Eglinton Avenue East & Eglinton Avenue West", "Eglinton Avenue East (1)"));
		CHECK(are_directly_connected("Bay Street & Dundas Street West", "Bay Street (6)"));
		CHECK(are_directly_connected("Bay Street & Wellington Street West", "Bay Street (20)"));
		CHECK(are_directly_connected("Yonge Street & Dundas Street West & Dundas Street East", "Dundas Street East"));
		CHECK(are_directly_connected("Yonge Street & College Street & Carlton Street", "Carlton Street"));
		CHECK(are_directly_connected("Yonge Street & Queen Street West & Queen Street East", "Queen Street East"));
		CHECK(are_directly_connected("Bay Street & Adelaide Street West", "Bay Street (17)"));
		CHECK(are_directly_connected("Yonge Street & King Street West & King Street East", "King Street East"));
		CHECK(are_directly_connected("Yonge Street & Bloor Street East & Bloor Street West", "Bloor Street East (3)"));
		CHECK(are_directly_connected("Bloor Street West & Bay Street", "Bay Street (9)"));
		CHECK(are_directly_connected("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West", "Saint Clair Avenue West"));
		CHECK(are_directly_connected("University Avenue & Front Street West & York Street", "York Street"));
		CHECK(are_directly_connected("Yonge Street & Adelaide Street West & Adelaide Street East", "Adelaide Street East"));
		CHECK(are_directly_connected("Yonge Street & Gerrard Street West & Gerrard Street East", "Gerrard Street East"));
		CHECK(are_directly_connected("Bloor Street East & Church Street", "Church Street"));
		CHECK(are_directly_connected("King Street West & Bay Street", "King Street West (41)"));
		CHECK(are_directly_connected("University Avenue & Dundas Street West", "University Avenue (1)"));
		CHECK(are_directly_connected("St. George Street & Harbord Street & Hoskin Avenue", "St. George Street (5)"));
		CHECK(are_directly_connected("College Street & Bay Street", "Bay Street (2)"));
		CHECK(are_directly_connected("Queen Street West & John Street", "John Street (3)"));
		CHECK(are_directly_connected("Yonge Street & Wellesley Street East & Wellesley Street West", "Wellesley Street East"));
		CHECK(are_directly_connected("Queen Street West & Bay Street", "Bay Street (23)"));
		CHECK(are_directly_connected("Avenue Road & Bloor Street West & Queen's Park", "Bloor Street West (53)"));
		CHECK(are_directly_connected("Front Street West & John Street & Convention centre loading dock", "John Street (1)"));
		CHECK(are_directly_connected("University Avenue & Wellington Street West", "University Avenue (34)"));
		
		//Intersections that should NOT be directly connected
		CHECK(!are_directly_connected("University Avenue & Dundas Street West", "University Avenue (35)"));
		CHECK(!are_directly_connected("Yonge Street & Eglinton Avenue East & Eglinton Avenue West", "Bay Street & Dundas Street West"));
		CHECK(!are_directly_connected("Bay Street & Wellington Street West", "Yonge Street & Dundas Street West & Dundas Street East"));
		CHECK(!are_directly_connected("Yonge Street & College Street & Carlton Street", "Yonge Street & Queen Street West & Queen Street East"));
		CHECK(!are_directly_connected("Bay Street & Adelaide Street West", "Yonge Street & King Street West & King Street East"));
		CHECK(!are_directly_connected("Yonge Street & Bloor Street East & Bloor Street West", "Bloor Street West & Bay Street"));
		CHECK(!are_directly_connected("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West", "University Avenue & Front Street West & York Street"));
		CHECK(!are_directly_connected("Yonge Street & Adelaide Street West & Adelaide Street East", "Yonge Street & Gerrard Street West & Gerrard Street East"));
		CHECK(!are_directly_connected("Bloor Street East & Church Street", "King Street West & Bay Street"));
		CHECK(!are_directly_connected("University Avenue & Dundas Street West", "St. George Street & Harbord Street & Hoskin Avenue"));
		CHECK(!are_directly_connected("College Street & Bay Street", "Queen Street West & John Street"));
		CHECK(!are_directly_connected("Yonge Street & Wellesley Street East & Wellesley Street West", "Queen Street West & Bay Street"));
		CHECK(!are_directly_connected("Avenue Road & Bloor Street West & Queen's Park", "Front Street West & John Street & Convention centre loading dock"));
	}

	TEST_FIXTURE(Map_Fixture, intersections_adjacent_segments_functionality) {
		std::vector<unsigned> result;
		std::vector<unsigned> expected_result;
		
		expected_result = {1649, 29672, 100022, 141896};
		result = find_adjacent_intersections("Yonge Street & Eglinton Avenue East & Eglinton Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {23161, 151756, 151758, 151759};
		result = find_adjacent_intersections("Bay Street & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {58113, 58115, 131820};
		result = find_adjacent_intersections("Bay Street & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2299, 39698, 61973, 151761};
		result = find_adjacent_intersections("Yonge Street & Dundas Street West & Dundas Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {3024, 27812, 27813, 45964};
		result = find_adjacent_intersections("Yonge Street & College Street & Carlton Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2523, 50826, 50827, 50831};
		result = find_adjacent_intersections("Yonge Street & Queen Street West & Queen Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {58110, 63375, 102504};
		result = find_adjacent_intersections("Bay Street & Adelaide Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {10539, 58109, 102506, 102507};
		result = find_adjacent_intersections("Yonge Street & King Street West & King Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1897, 39683, 155043, 160437};
		result = find_adjacent_intersections("Yonge Street & Bloor Street East & Bloor Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {27815, 39758, 117270, 155041};
		result = find_adjacent_intersections("Bloor Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {660, 148746, 148747};
		result = find_adjacent_intersections("Yonge Street & Saint Clair Avenue East & Saint Clair Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {9556, 63376, 63378, 63380};
		result = find_adjacent_intersections("University Avenue & Front Street West & York Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2973, 102508, 102509};
		result = find_adjacent_intersections("Yonge Street & Adelaide Street West & Adelaide Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {3483, 39699, 40414, 153566};
		result = find_adjacent_intersections("Yonge Street & Gerrard Street West & Gerrard Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1852, 114378, 152223, 165157};
		result = find_adjacent_intersections("Bloor Street East & Church Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {58106, 58108, 58111, 58112};
		result = find_adjacent_intersections("King Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5439, 151755, 152010};
		result = find_adjacent_intersections("University Avenue & Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1375, 11644, 130811, 162231};
		result = find_adjacent_intersections("St. George Street & Harbord Street & Hoskin Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5721, 45961, 45962, 154067};
		result = find_adjacent_intersections("College Street & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5599, 5635, 133401, 133402};
		result = find_adjacent_intersections("Queen Street West & John Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {3370, 160438, 160439};
		result = find_adjacent_intersections("Yonge Street & Wellesley Street East & Wellesley Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {63372, 115704, 115705, 154265};
		result = find_adjacent_intersections("Queen Street West & Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {130356, 130358, 157414, 157460};
		result = find_adjacent_intersections("Avenue Road & Bloor Street West & Queen's Park");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {5449, 116228, 156306};
		result = find_adjacent_intersections("Front Street West & John Street & Convention centre loading dock");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {73003, 151334, 158369};
		result = find_adjacent_intersections("University Avenue & Wellington Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, streets_segments_functionality) {
		std::vector<unsigned> result;
		std::vector<unsigned> expected_result;
		
		expected_result = {76, 77, 78, 79, 80, 81, 82, 5563, 5564, 5565, 7475, 7476, 10842, 10843, 13401, 13402, 13403, 13404, 13405, 17534, 22425, 22426, 22427, 22428, 22429, 22470, 22471, 22472, 22473, 22474, 22475, 22476, 22477, 27021, 27022, 27023, 27024, 27025, 27026, 27027, 35053, 35054, 36667, 36668, 36698, 36699, 36700, 36701, 36702, 39082, 39083, 39084, 39085, 39086, 39107, 39108, 39109, 39110, 39111, 39112, 39113, 39959, 39960, 46851, 46852, 48776, 48777, 48778, 48779, 51193, 51194, 51195, 51196, 51197, 51198, 51199, 51212, 51213, 54859, 54860, 54861, 54862, 54863, 64032, 64033, 64034, 64035, 64036, 66483, 66484, 69413, 78118, 78119, 78120, 78121, 78122, 78123, 78124, 78125, 79250, 79251, 79252, 79253, 79254, 79255, 79256, 79257, 79258, 79259, 79260, 79261, 79277, 79278, 79279, 79280, 79281, 79282, 79283, 79284, 79285, 79286, 79287, 79288, 79289, 79290, 91983, 91984, 91985, 91986, 91987, 91988, 91991, 91997, 91998, 92002, 95250, 95251, 95252, 95253, 95254, 95255, 95256, 95257, 95258, 95259, 95260, 95261, 95262, 95263, 95264, 95265, 95266, 95267, 95268, 95269, 95270, 95271, 95272, 95273, 95274, 95275, 95276, 95277, 95278, 95279, 95280, 95281, 95282, 95283, 95284, 95285, 95286, 95287, 95288, 95289, 95290, 95291, 95292, 95293, 95294, 95295, 95329, 95330, 95331, 95332, 95373, 95374, 95375, 95376, 95377, 95378, 95379, 95380, 95381, 95382, 99353, 99354, 99355, 99356, 99358, 99359, 99361, 99362, 99363, 99364, 99365, 99366, 99367, 99368, 99369, 99370, 99375, 99376, 99378, 99379, 99388, 99389, 99390, 99391, 99392, 99393, 99400, 99401, 99402, 99403, 99404, 99405, 99406, 99407, 99408, 99409, 99410, 99414, 99415, 99419, 99420, 99421, 99422, 99424, 99425, 99426, 99427, 99428, 99429, 99430, 99431, 99479, 99480, 99482, 99483, 99484, 99485, 99486, 99492, 99499, 99500, 99501, 99502, 99503, 99504, 99505, 99506, 99507, 99508, 111875, 111876, 112762, 113281, 113282, 113283, 113284, 113508, 113509, 115091, 115092, 115096, 115097, 115098, 115099, 115151, 115152, 115153, 115154, 115155, 115156, 115178, 115179, 115180, 115181, 115182, 115183, 115184, 115185, 115186, 115187, 115188, 115189, 115190, 115191, 115192, 115193, 115194, 115195, 115196, 115197, 115200, 115201, 115206, 115209, 115210, 115211, 115212, 116580, 116581, 116790, 117449, 117450, 117451, 117452, 117453, 117454, 117455, 118023, 118024, 118025, 118026, 118027, 118028, 118029, 128975, 128976, 128978, 128979, 128980, 128983, 128984, 128985, 128986, 128988, 128989, 128992, 128993, 128998, 128999, 129186, 129189, 129190, 129191, 129202, 129203, 129205, 129206, 129207, 129216, 129233, 129234, 129236, 129237, 129244, 129245, 129246, 129247, 129248, 129257, 129271, 129272, 129283, 129284, 129285, 129296, 129301, 129302, 129312, 129313, 129314, 129315, 129316, 129317, 129318, 129319, 129321, 129322, 129325, 129328, 129336, 129337, 129338, 129339, 129340, 129344, 129377, 129378, 129379, 129380, 129381, 129382, 129383, 129384, 129385, 129386, 129387, 129388, 131889, 131890, 131891, 131892, 131893, 131894, 131895, 131896, 132002, 132003, 132004, 132005, 132006, 132007, 132009, 132025, 132026, 132027, 132038, 132039, 132041, 132042, 132043, 132045, 132046, 132048, 132049, 132050, 132055, 132056, 132057, 132058, 132059, 132061, 132062, 132063, 132064, 132070, 132071, 132072, 132073, 132075, 132076, 132083, 132084, 132086, 132087, 132088, 132091, 132093, 132094, 132095, 134258, 134259, 134534, 134535, 134538, 134539, 138147, 138580, 141802, 141803, 141804, 141806, 141807, 142866, 142869, 151726, 151727, 153116, 153117, 153118, 153119, 153120, 153121, 153122, 153123, 153124, 153125, 155713, 155901, 155902, 155903, 155904, 156600, 156601, 157272, 157273, 157274, 157275, 165382, 165383, 172705, 172706, 172707, 172708, 173082, 173083, 173088, 173985, 173986, 174070, 174071, 174072, 174073, 174074, 174075, 174076, 174077, 174078, 174079, 174080, 174083, 174084, 174085, 174086, 174087, 174088, 174089, 174090, 174091, 174092, 174093, 174121, 174122, 174123, 174124, 174125, 174126, 174127, 174128, 174129, 174130, 174131, 174132, 174168, 174169, 174170, 174171, 174172, 174173, 174174, 174175, 174176, 174177, 174363, 174364, 174365, 174366, 174909, 174910, 176323, 177214, 177215, 177216, 177403, 177404, 183640, 183641, 183642, 183643, 183644, 183645, 183646, 183647, 183648, 183649, 183650, 183651, 183652, 183653, 183654, 183655, 183656, 183657, 183658, 183659, 183660, 185730, 185731, 186020, 186021, 186022, 186023, 186024, 186025, 186026, 186027, 186028, 186029, 186030, 186031, 186032, 186033, 186034, 186170, 186171, 186172, 186218, 186219, 186220, 186221, 186853, 186854, 187397, 190810, 191086, 191087, 191096, 191097, 191098, 191118, 191119, 191120, 191121, 191122, 191123, 191124, 191561, 191562, 191563, 191564, 191565, 191566, 191567, 191575, 191576, 191577, 191578, 191579, 192517, 192518, 192519, 194499, 194500, 194501, 194502, 194503, 195888, 195889, 195890, 195891, 195892, 195893, 195918, 195919, 195920, 195921, 195922, 195923, 195924, 195925, 195926, 196506, 197441, 197442, 198496, 198497, 198498, 198765, 198766, 199717, 199718, 199719, 199720, 199721, 199722, 200493, 201768, 201769, 201794, 201795, 201796, 201797, 201798, 201799, 201800, 201801, 201802, 201803, 201804, 201805, 201806, 201807, 201813, 201814, 203095, 203096, 203770, 203771, 203772, 203773, 203774, 203775, 203776, 203777, 203778, 203779, 203780, 203781, 203782, 203783, 203784, 203785, 205490, 205699, 206483, 206484, 206485, 207377, 207378, 207379, 207380, 207381, 207382, 207383, 207384, 207385, 207386, 207387, 207388, 207389, 207390, 207391, 207564, 207565, 207566, 207567, 207568, 207569, 207570, 207897, 209697, 209698, 209699, 209700, 209701, 209702, 209703, 209704, 209705, 210709, 210764, 211077, 211078, 211079, 211080, 211081, 211082, 211083, 211084, 211085, 211086, 211087, 211088, 211089, 211090, 211091, 211092, 211093, 211094, 211095, 211096, 211097, 211182, 211183, 211184, 211185, 211186, 211187, 211188, 211189, 214498};
		result = find_street_street_segments("Yonge Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {659, 1376, 1377, 3660, 3661, 3662, 3663, 3664, 3665, 3666, 5822, 5823, 5824, 10083, 10084, 10085, 10086, 10087, 16226, 22322, 22323, 22324, 22715, 22716, 22717, 22718, 22737, 22738, 22739, 24148, 24149, 30657, 30658, 30659, 30660, 30661, 34495, 34496, 34497, 34498, 34499, 34500, 34501, 34502, 34503, 34504, 34505, 34506, 34507, 34508, 34509, 34510, 34511, 34512, 34513, 34514, 34972, 34973, 34974, 40650, 40651, 40652, 40662, 40663, 41189, 41190, 41233, 41234, 41235, 41236, 41237, 41238, 41239, 42538, 42539, 42540, 58612, 58654, 58655, 59461, 59462, 59463, 59469, 63502, 63503, 63504, 63505, 63506, 73475, 93581, 93582, 93583, 93585, 93586, 93588, 93591, 93592, 93593, 93594, 93595, 93596, 93597, 93598, 93599, 93600, 93601, 93602, 93603, 93604, 93617, 93618, 93622, 93623, 93624, 93628, 93629, 93630, 93631, 93632, 93633, 93634, 93635, 93636, 93637, 93638, 93639, 93640, 93641, 93642, 93643, 93659, 93660, 93661, 93662, 93663, 93664, 93673, 93674, 93675, 93678, 93680, 93681, 93682, 93683, 93687, 93688, 93689, 93690, 93691, 93692, 93693, 93745, 93746, 93747, 93748, 93749, 93750, 93751, 93752, 93753, 93754, 93755, 93758, 93759, 93768, 93769, 93770, 93772, 93773, 93774, 93775, 93776, 93777, 93778, 93779, 93780, 113330, 113381, 113382, 113383, 113384, 115552, 116035, 131305, 131306, 131307, 131308, 131309, 131310, 131311, 131315, 131316, 131317, 131318, 131319, 131320, 131321, 131322, 131323, 133795, 133796, 133797, 133798, 135711, 135712, 135713, 138120, 138121, 138122, 138123, 143917, 143918, 143919, 143920, 143921, 143922, 143923, 143924, 143925, 143926, 143927, 143928, 143929, 143930, 143931, 143932, 143933, 143934, 143935, 143936, 143937, 143938, 143939, 143940, 143941, 143942, 143943, 143944, 143945, 143946, 143947, 143948, 143949, 143950, 143951, 143952, 143953, 143954, 143955, 143956, 143957, 143958, 143959, 143960, 143961, 143962, 143963, 143964, 143965, 143966, 143967, 143968, 143969, 143970, 143971, 143972, 143973, 143974, 143975, 155030, 155031, 155032, 155033, 155034, 155035, 155036, 155037, 155038, 155039, 155040, 155041, 155042, 155043, 155044, 155045, 155046, 155047, 155048, 155049, 155050, 155051, 155052, 155053, 155054, 155055, 155056, 155057, 155058, 155059, 155060, 155061, 155062, 155063, 155162, 155163, 155164, 155165, 155166, 155167, 155168, 155169, 155426, 155427, 155428, 155429, 156249, 157080, 157510, 157511, 157512, 157513, 157514, 157515, 157516, 157517, 157518, 157519, 157520, 157521, 157522, 161600, 161601, 161602, 161603, 161604, 161605, 161606, 161607, 161608, 161609, 161610, 161611, 161612, 161613, 173757, 173758, 173759, 173760, 173761, 173762, 173763, 173764, 173765, 173766, 173767, 173790, 173791, 173792, 173793, 173794, 173795, 173796, 173797, 176514, 179152, 179153, 179154, 179155, 180121, 180124, 180125, 180126, 180127, 180135, 180136, 180137, 180138, 180139, 180151, 180152, 180153, 180432, 180433, 180434, 180435, 180436, 180437, 180438, 180439, 181407, 181408, 181409, 182738, 182739, 182740, 182741, 182742, 182748, 182749, 182750, 182751, 182752, 182768, 182892, 182893, 183071, 183072, 183073, 183074, 187010, 187011, 187012, 187013, 188469, 188470, 188471, 188575, 188576, 188577, 188578, 188584, 188585, 189434, 189435, 192099, 192100, 192101, 192102, 193627, 193628, 193631, 193632, 193633, 193634, 193635, 194486, 195884, 198767, 198768, 199447, 199448, 199449, 200039, 200040, 202711, 202712, 202713, 202714, 202715, 202716, 202717, 202718, 202719, 202720, 202721, 202722, 202723, 202724, 202725, 202726, 208002, 208003, 208299, 208300, 208301, 208344, 208345, 208346, 208347, 209417, 209709, 209710, 209711, 209712, 209714, 209715, 209716, 209717, 209718, 209719, 209753, 209754, 209888, 209889, 209891, 209892, 209893, 214134};
		result = find_street_street_segments("Eglinton Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1060, 1061, 5037, 5038, 22398, 22399, 22400, 22408, 22409, 22410, 22411, 22422, 22423, 22424, 27028, 27029, 31690, 31691, 39955, 39956, 39957, 39958, 45770, 46849, 46850, 59594, 59595, 59596, 59597, 59598, 59599, 59600, 59601, 59602, 65867, 65868, 65869, 65870, 65871, 65872, 65873, 74365, 74366, 74367, 74368, 107633, 107634, 107662, 107663, 107785, 112714, 112715, 113499, 113500, 113501, 113502, 113503, 113504, 136561, 136562, 136563, 136564, 136565, 136566, 136567, 141746, 141747, 146755, 146756, 146757, 155707, 176182, 176183, 176184, 176185, 176186, 179437, 183354, 183355, 183356, 183357, 183358, 183359, 183360, 183361, 186628, 186629, 186630, 186631, 186632, 186633, 186634, 186635, 186636, 186637, 186638, 186639, 186640, 186645, 186646, 187770, 187771, 189079, 189080, 192103, 192104, 192954, 192955, 192956, 192957, 193236, 193237, 193238, 193239, 193240, 193241, 193242, 196073, 196074, 196075, 196076, 196077, 196078, 196080, 196081, 196082, 208922, 211815, 211816};
		result = find_street_street_segments("Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 2034, 2035, 2036, 2037, 6116, 6117, 6118, 6119, 6182, 6183, 6184, 6185, 6186, 6187, 6188, 6189, 7939, 8103, 8104, 8105, 9810, 9811, 9812, 9813, 15714, 15715, 15716, 15717, 15718, 16362, 16363, 16364, 16365, 16366, 16367, 16368, 16369, 16370, 16371, 16372, 35413, 35414, 35415, 40360, 40361, 40401, 40402, 40403, 40404, 40405, 40406, 41242, 41243, 41244, 41245, 41246, 41247, 41248, 41249, 41250, 59573, 59574, 59576, 59577, 64370, 64371, 65523, 65524, 73351, 73352, 73353, 73354, 73355, 73356, 73357, 73358, 73359, 73360, 73361, 73587, 73588, 75536, 75537, 75538, 75539, 75540, 75541, 75542, 75543, 75544, 75545, 90657, 90849, 90850, 90851, 90853, 90854, 90857, 90858, 90859, 90860, 90861, 90862, 90864, 90865, 90868, 90869, 90871, 90872, 90873, 90874, 90877, 90878, 90879, 90880, 90881, 90882, 90883, 90884, 90885, 90886, 90946, 90964, 90965, 90966, 90967, 90968, 90969, 90970, 90971, 90972, 90973, 91327, 91328, 91329, 91330, 91331, 91332, 91333, 91334, 103742, 103743, 103744, 103745, 103746, 103747, 103748, 103749, 103750, 103751, 103754, 103755, 103756, 103757, 103758, 103759, 103760, 103761, 103762, 103763, 105103, 105110, 105111, 105112, 105113, 105114, 105115, 105116, 105117, 105118, 105119, 105120, 105121, 105122, 105123, 105124, 105125, 109094, 109095, 109096, 109097, 109098, 109099, 117351, 117352, 117357, 117358, 117359, 117360, 119495, 119496, 119497, 120595, 120596, 120758, 129986, 129987, 136588, 136606, 136607, 136608, 136609, 136610, 136611, 136612, 136613, 139767, 139768, 139769, 139770, 139771, 139772, 139959, 139975, 140821, 140822, 140823, 140824, 142372, 143426, 143427, 143428, 143430, 143431, 143432, 143437, 143439, 143447, 143448, 143449, 143450, 143451, 143452, 143453, 143458, 143459, 143461, 143462, 143464, 143470, 143471, 143472, 143484, 143485, 143486, 143487, 143488, 143515, 143516, 143520, 145815, 145816, 145817, 145884, 145885, 145886, 145887, 145888, 145891, 145892, 156469, 158849, 158850, 158851, 158852, 158853, 158854, 158855, 162553, 162554, 162555, 162556, 162557, 162558, 162559, 162560, 162561, 162562, 162563, 166525, 166526, 166527, 166528, 166529, 166530, 166531, 171745, 171746, 171747, 171748, 171749, 171750, 171751, 171752, 171753, 171754, 171755, 179450, 179451, 179452, 182264, 182265, 182266, 182267, 182288, 182289, 182290, 182338, 182339, 182340, 182341, 182342, 182343, 182344, 182345, 182349, 182350, 184385, 184386, 186543, 188759, 188760, 188761, 188762, 188763, 188764, 188765, 188766, 188767, 188768, 189076, 189077, 189081, 189082, 189083, 189084, 189085, 189086, 189544, 189545, 189546, 189547, 189548, 189549, 189550, 189551, 189552, 189553, 189554, 189555, 189556, 189557, 189558, 189559, 189560, 189561, 192282, 192283, 192284, 192285, 192322, 192323, 192324, 192325, 192326, 192327, 192328, 192329, 192330, 192331, 192332, 192343, 192344, 192345, 193037, 193038, 200017, 200018, 200019, 200043, 200044, 200289, 200290, 200291, 202394, 202395, 202396, 202397, 202398, 202399, 202400, 202401, 202402, 202403, 202404, 202405, 202406, 202407, 202408, 202409, 202410, 202411, 202412, 202413, 202414, 202415, 202416, 202417, 202418, 202419, 202420, 202421, 202422, 202423, 202424, 202425, 202426, 202427, 202428, 202429, 202430, 202431, 202432, 202433, 202434, 202435, 202436, 202437, 202438, 202439, 202440, 202441, 202442, 202443, 202444, 202445, 202446, 202447, 202448, 202449, 202453, 203564, 205734, 205735, 205736, 205737, 205738, 208169, 208170, 208171, 208172, 208173, 208174, 208175, 208176, 208177, 208178, 208179, 208180, 208181, 208419, 208420, 208421, 208422, 208423, 208424, 208425, 208426, 208427, 208428, 208429, 208430, 208431, 208432, 208433, 208434, 208435, 208438, 208439, 208440, 208441, 208763, 208764, 208765, 208766, 208767, 208883, 208884, 208885, 208886, 208887, 208888, 208889, 209572, 209573, 209574, 209575};
		result = find_street_street_segments("Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {783, 784, 785, 786, 6140, 6141, 6142, 6143, 10356, 10357, 10831, 10832, 12739, 12740, 16934, 16935, 16936, 16937, 16938, 16939, 45724, 45725, 45726, 45727, 45728, 45729, 45762, 45763, 45764, 45765, 45766, 45767, 45768, 45769, 86583, 86596, 111249, 111250, 111251, 111252, 111253, 111254, 111255, 111256, 111257, 111258, 111259, 111260, 111261, 111262, 111263, 111264, 111265, 111266, 111267, 111268, 111269, 111270, 111271, 111272, 111273, 111274, 111275, 111276, 111277, 111278, 111279, 111280, 111281, 111282, 111283, 111284, 111285, 111286, 111287, 111288, 111289, 111290, 111291, 111292, 111293, 111294, 111295, 111296, 203184, 203185, 203186, 203187, 203188, 203189, 203190, 203191, 203192, 203193, 203194, 203195, 203196, 203197, 203198, 206995, 206996, 206997, 206998, 206999, 207000, 207001, 207002, 211154, 211155, 211156, 211157, 211158, 211159, 211160, 211161, 211162, 211163, 211164, 211165, 211166, 211167, 211168, 211169, 211170, 211171};
		result = find_street_street_segments("College Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {397, 398, 399, 400, 401, 4777, 4778, 4779, 4780, 4781, 4782, 4783, 6190, 6191, 6192, 6193, 6194, 7133, 7134, 7135, 16060, 16061, 16062, 16063, 16064, 16065, 16066, 16963, 16964, 16965, 16966, 16967, 16968, 22740, 22741, 22742, 22743, 22744, 27119, 27120, 27121, 45722, 45723, 65875, 65876, 73722, 73723, 73724, 73725, 73726, 73727, 76712, 76713, 76714, 76715, 76716, 76717, 76718, 76719, 134251, 134252, 134253, 134254, 134255, 134256, 134475, 134478, 134479, 159408, 159409, 159410, 159411, 159412, 189078, 189803, 189804, 189805, 189806, 189807, 189808, 189809, 200060, 200061, 200062};
		result = find_street_street_segments("University Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {361, 362, 363, 364, 738, 739, 740, 1416, 7041, 8100, 15260, 15261, 15262, 15263, 15264, 15265, 15266, 15267, 15268, 15269, 15270, 15271, 17253, 17254, 17255, 17256, 17257, 17258, 17259, 17260, 17261, 17262, 28470, 39180, 39181, 39348, 39349, 39350, 39351, 40396, 40397, 40398, 45162, 45163, 45164, 45165, 45166, 45733, 45844, 45845, 45846, 45847, 45848, 45849, 45850, 45851, 45852, 55382, 55383, 55384, 55385, 55386, 58833, 58834, 58835, 58836, 58837, 58838, 58839, 58840, 58841, 58842, 58843, 58844, 59570, 59571, 59572, 59575, 59578, 59579, 65517, 65518, 65519, 65520, 89012, 89013, 89014, 89015, 89016, 89017, 89018, 89025, 89026, 89029, 89030, 89032, 89033, 89036, 89039, 89040, 89041, 89042, 89044, 89047, 89048, 89049, 89050, 89051, 89052, 90922, 90923, 90924, 90926, 90949, 90950, 90951, 90952, 90953, 103579, 103580, 103581, 103582, 103584, 103585, 103587, 103591, 103592, 103594, 103595, 103596, 103602, 103605, 103606, 103607, 103612, 103613, 103614, 103615, 103616, 103617, 103618, 115907, 115908, 115909, 115910, 115936, 115945, 115946, 115947, 115948, 115949, 115950, 117856, 117857, 117858, 117859, 117860, 117861, 117862, 117863, 117864, 117865, 117866, 117867, 154789, 154790, 154791, 154792, 154793, 154794, 154795, 154796, 154797, 154798, 154799, 154800, 158730, 159492, 159493, 159494, 159495, 159496, 159497, 159498, 159499, 159500, 159501, 159502, 159503, 159504, 159505, 159506, 159507, 159559, 159560, 174327, 174330, 174331, 174332, 174333, 174334, 174335, 174336, 180049, 180050, 180051, 184057, 184058, 186524, 186525, 186526, 186527, 186528, 186529, 186530, 186531, 186532, 186533, 186534, 186535, 186536, 186541, 189038, 189039, 189040, 189041, 189042, 189043, 189044, 189045, 189046, 189047, 189048, 189049, 189110, 189111, 189112, 189113, 189114, 189115, 189116, 189117, 189118, 190513, 190514, 190663, 190664, 193135, 194441, 194442, 194443, 194444, 194445, 194446, 194447, 194511, 194512, 194513, 194514, 194515, 194516, 194517, 196431, 200015, 200016, 207413, 207414, 207415, 207416, 207417, 208413, 208414, 208415, 211530, 211531, 211584, 211585, 211586, 211587, 211588, 211589, 211590, 211591, 211592, 211593, 212954, 212955, 212956, 212957, 212958, 212959, 212960, 213288, 213289, 213290, 213291, 213704};
		result = find_street_street_segments("Bloor Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {359, 360, 3719, 3720, 3721, 3722, 3723, 5184, 5185, 5186, 5187, 5188, 5189, 5190, 5191, 5192, 5193, 5194, 5195, 5196, 5197, 5198, 5199, 5200, 5201, 5202, 5203, 5204, 5205, 5206, 5207, 5208, 5209, 28689, 28690, 28691, 28692, 28693, 28694, 28695, 28696, 40427, 40428, 40429, 40430, 40431, 40432, 63988, 63989, 63990, 64683, 64684, 64685, 64686, 64687, 64688, 64689, 64690, 64691, 64692, 64693, 64694, 64695, 64696, 64697, 64698, 64699, 64700, 64701, 64702, 64703, 64704, 64705, 64706, 64707, 64708, 64709, 64710, 64711, 64712, 64713, 64714, 64715, 64716, 64717, 64718, 64719, 64720, 64721, 64722, 64723, 64724, 64725, 64726, 64727, 64728, 64729, 64730, 64731, 64732, 64733, 64734, 64735, 64736, 64737, 64738, 74987, 74988, 74989, 96163, 96164, 96165, 96180, 96181, 96183, 96184, 96185, 96186, 96187, 96188, 96199, 96200, 96201, 96206, 96207, 96222, 96223, 96224, 96225, 138155, 138156, 138157, 138158, 138159, 138160, 138161, 138162, 138163, 138164, 138165, 138166, 138167, 138168, 138169, 138170, 138171, 138172, 138173, 138174, 138175, 138176, 138177, 138178, 138179, 138180, 156266, 156267, 189103, 189104, 189105};
		result = find_street_street_segments("Danforth Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723, 6128, 6129, 6148, 6149, 18345, 18346, 48317, 48318, 48492, 48493, 48494, 48499, 48500, 48501, 48502, 48503, 48504, 48505, 48506, 48507, 48508, 48509, 51200, 51201, 64251, 64252, 64374, 64375, 64376, 107613, 107614, 107618, 107619, 107620, 107641, 107642, 107646, 107650, 107651, 107652, 107653, 107675, 107676, 107677, 107682, 107683, 107752, 107767, 107773, 107774, 107780, 107781, 107782, 107797, 107799, 119674, 119675, 119686, 119687, 133591, 133592, 133593, 133605, 133606, 134476, 134477, 134480, 134481, 134482, 134483, 134484, 134485, 134486, 134487, 134488, 134489, 134490, 134491, 134492, 135184, 135185, 135186, 135187, 135188, 135189, 135190, 159695, 159696, 159697, 159698, 159699, 189145, 189146, 189149, 189150, 189151, 189152, 189153, 189154, 189155, 189156, 189157, 189158, 189159, 189160, 189161, 189162, 189163, 189164, 189182, 189183, 189184, 189185, 189186, 189187, 189188, 189189, 189190, 189191, 189248, 189249, 189250, 189251, 189252, 189253, 189254, 189255, 197195, 197196, 197197, 197198, 197199, 197200, 197201, 197202, 197203, 197204, 197205, 197206, 197207, 197208, 197209, 208129, 208130, 208131, 208132, 208133, 208134, 208135, 208136, 208137, 208138, 208139, 208140, 208141, 208142, 208143};
		result = find_street_street_segments("Queen Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2180, 2181, 2182, 9725, 9726, 9727, 9728, 9729, 9821, 9822, 22387, 22388, 22389, 22390, 22391, 22392, 22393, 22394, 22395, 22396, 22397, 35620, 35621, 35622, 36602, 36603, 36604, 36605, 36606, 38150, 38151, 38152, 38153, 38154, 38155, 38156, 38157, 38158, 38159, 41894, 41895, 41896, 41897, 41898, 41899, 41900, 41901, 41902, 41903, 41904, 41905, 41906, 48322, 48323, 51202, 51203, 51204, 51205, 51206, 51207, 51208, 51209, 51210, 51211, 53079, 53080, 53081, 64043, 64044, 64045, 64046, 64047, 64048, 64049, 64050, 64051, 64052, 64053, 64054, 64055, 64056, 64057, 64058, 64059, 64060, 64061, 64062, 64063, 64064, 64065, 64066, 64067, 64068, 64069, 64070, 64071, 64072, 64077, 64078, 112623, 112624, 112625, 112626, 112627, 112628, 112629, 112630, 112631, 112632, 112633, 112634, 112635, 112636, 112637, 112638, 112639, 112640, 112641, 112642, 112643, 112644, 112645, 112646, 112647, 112648, 112649, 112650, 112651, 112652, 112653, 112654, 112655, 112656, 112657, 112658, 112659, 112660, 112661, 112662, 112663, 112664, 112665, 112666, 112667, 112668, 112669, 112670, 112671, 112672, 112673, 116102, 121914, 121915, 121916, 121917, 121918, 121919, 121920, 121921, 121922, 121923, 123461, 123462, 123463, 123464, 123465, 123466, 123467, 123468, 123469, 123470, 123471, 123472, 130902, 130903, 130904, 130905, 130906, 130907, 130908, 130909, 130910, 130911, 130912, 130944, 130945, 139303, 139304, 139305, 139306, 142093, 142097, 142099, 142100, 147252, 147253, 147256, 151151, 151152, 151815, 151816, 151817, 151818, 151819, 184223, 194913, 194914, 194915, 194916, 194917, 194918, 194919, 194920, 200715, 200716, 200717, 211339, 211340, 211341, 211342, 211343, 211344, 211345, 211346, 211347, 211348, 211349, 211350, 211351, 211352, 211353, 211354, 211355, 211356, 211357, 211358, 211359, 211360, 211361, 211362, 211363, 211364, 211365, 211366, 211367, 211368, 211369, 211370, 211371, 211372};
		result = find_street_street_segments("Queen Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {19, 402, 403, 11620, 11621, 16212, 16213, 16214, 16215, 16216, 16217, 19768, 73957, 73958, 73959, 73960, 73961, 73962, 73963, 73964, 108121, 108122, 108123, 108124, 108128, 108129, 108130, 108138, 108139, 108140, 108141, 112826, 112827, 112828, 113319, 113320, 113321, 113322, 113323, 113324, 113325, 114131, 114132, 114133, 114134, 114135, 114136, 114137, 114138, 114139, 114140, 114141, 114142, 114143, 114181, 114182, 114183, 114184, 114262, 114263, 114264, 114271, 114272, 114273, 114274, 114275, 114276, 114732, 114733, 115618, 115619, 115620, 115621, 115622, 115625, 115634, 116504, 116505, 116506, 116507, 116508, 116509, 116510, 116511, 116512, 116513, 116514, 116515, 116516, 116517, 116518, 116519, 116520, 116521, 116522, 116523, 133843, 133844, 133845, 133846, 133847, 133848, 133849, 133851, 141752, 141753, 141754, 141755, 141756, 141757, 141758, 141765, 141766, 141767, 141768, 141769, 141770, 141771, 141772, 141773, 141774, 141775, 141776, 141777, 147106, 147107, 147108, 147109, 147110, 147111, 147112, 147113, 147114, 147115, 147116, 147117, 147118, 152595, 152596, 152597, 152598, 152698, 152699, 152700, 152701, 152702, 156655, 156660, 156661, 156662, 156663, 156664, 156665, 156666, 156667, 156668, 156673, 159865, 178642, 178643, 178644, 178645, 178646, 178647, 178648, 178649, 178650, 178651, 178652, 178653, 178654, 178655, 178656, 178657, 178658, 178659, 178660, 178661, 183694, 183695, 183696, 198499, 198500, 198501, 199932, 199933, 199934, 200478, 200479, 200480, 201760, 201761, 204638, 206489, 206490, 206491, 206492, 206493, 206494, 206495, 206496};
		result = find_street_street_segments("Avenue Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {461, 462, 463, 541, 542, 543, 544, 545, 546, 547, 589, 590, 591, 592, 593, 893, 894, 895, 896, 897, 898, 899, 8310, 8311, 8312, 17222, 17223, 17224, 19486, 19487, 19488, 19489, 19490, 19491, 19492, 19493, 19494, 28014, 28024, 28025, 39791, 39792, 39793, 39794, 39795, 39796, 39797, 39798, 39799, 42945, 42946, 42947, 42948, 42949, 50191, 50192, 50194, 50195, 50196, 50197, 50198, 50203, 50204, 50205, 50206, 50207, 50208, 50209, 58822, 58823, 58824, 58825, 58826, 58827, 58828, 58829, 58830, 58831, 58832, 64120, 64133, 64134, 64135, 64136, 64137, 64138, 64145, 64146, 64147, 64148, 64149, 64150, 64151, 64152, 64153, 64154, 64155, 65306, 65307, 65308, 65309, 65310, 65311, 65312, 69088, 69089, 73213, 73214, 85260, 85261, 85266, 85267, 85268, 85271, 85272, 85287, 85288, 85289, 85290, 85291, 85292, 85293, 85294, 85295, 85296, 85297, 85298, 92010, 92011, 92014, 92016, 92017, 92018, 92019, 92020, 92021, 92022, 92023, 92026, 92027, 92028, 92029, 92034, 92035, 92036, 92037, 92038, 92039, 92040, 92041, 92042, 92043, 92044, 92058, 92059, 92060, 92061, 92062, 92063, 92064, 92065, 92066, 92067, 92068, 92070, 92071, 92072, 92073, 92075, 92078, 92080, 92081, 92087, 92088, 92089, 92093, 92094, 92096, 92097, 92104, 92106, 92107, 92112, 92113, 92114, 92115, 92116, 92117, 94129, 94131, 94132, 94133, 94134, 94136, 94137, 94138, 94139, 94140, 106533, 106534, 106535, 106536, 106537, 106542, 106551, 106588, 106591, 106595, 106596, 106601, 106604, 106605, 106606, 106607, 106608, 106609, 106610, 106674, 106675, 106676, 106677, 106678, 106679, 106680, 106681, 106682, 106683, 106684, 106685, 106688, 106689, 106690, 106691, 106692, 106693, 111340, 111341, 111342, 111343, 111344, 111345, 112738, 112739, 112750, 112751, 112752, 112753, 113606, 113607, 113668, 113669, 114067, 114068, 114069, 114070, 114071, 114072, 114073, 114074, 114075, 114081, 116759, 116760, 116761, 116762, 116763, 116764, 116765, 116766, 116914, 116915, 116916, 116917, 116936, 116937, 116938, 116939, 116940, 116941, 116942, 116943, 116944, 116973, 116974, 116975, 116976, 116977, 116978, 116979, 116980, 116981, 116982, 116983, 116984, 116985, 116989, 116990, 116991, 116992, 116993, 123975, 123976, 123977, 123978, 123979, 123980, 123981, 123982, 123983, 123984, 123985, 123986, 123987, 124213, 124214, 129187, 129209, 129250, 129253, 129254, 129255, 129256, 129287, 139871, 139877, 139878, 139879, 139880, 139881, 139882, 139883, 139884, 139885, 139886, 139887, 139888, 139889, 139890, 139891, 141362, 141363, 141364, 141365, 141366, 141367, 141368, 141369, 141370, 141371, 152690, 152691, 152692, 152693, 152694, 152695, 152696, 152697, 155885, 155886, 155887, 155888, 155889, 155890, 155891, 155956, 158893, 158894, 158895, 158896, 158897, 158898, 158899, 158900, 158901, 158902, 158903, 158904, 158905, 158906, 158907, 168068, 168069, 168070, 168071, 176626, 176650, 176651, 176652, 176653, 176654, 176655, 176656, 181369, 181370, 181371, 181372, 181373, 181374, 181375, 181376, 181377, 181378, 181379, 181380, 181381, 181382, 181383, 181384, 181385, 181386, 184059, 184060, 184061, 184062, 184063, 184064, 184065, 184066, 184067, 184068, 184627, 184628, 184629, 184630, 186092, 186093, 187933, 187934, 187935, 188294, 189179, 189180, 189181, 195745, 195751, 195752, 199699, 199700, 199701, 200276, 200937, 200938, 200939, 200940, 200941, 203558, 203559, 203560, 203561, 203571, 203581, 203582, 203583, 203584, 203585, 203586, 203587, 203588, 203589, 203615, 203616, 203617, 203618, 203619, 203620, 203621, 203622, 203623, 203624, 204151, 204152, 205193, 205221, 205222, 205225, 205226, 205227, 205228, 205229, 205491, 205492, 205493, 205494, 205495, 205496, 205497, 205498, 205499, 205500, 205501, 205502, 205503, 205504, 205505, 205506, 205507, 205508, 207772, 207773, 207774, 207775, 207776, 207856, 207857, 207858, 207859, 207860, 207861, 207891, 207892, 207893, 207894, 207895, 207896, 211139, 211140, 211141, 211142, 211143, 211144, 211145, 211146, 211147, 211148, 211149, 211150, 211151, 211152, 211153, 211207, 211208, 211209, 211210, 211211, 211212, 214727};
		result = find_street_street_segments("Bathurst Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {572, 573, 574, 575, 576, 577, 578, 588, 926, 927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 943, 944, 945, 946, 947, 2648, 2649, 2650, 2651, 2652, 2653, 2654, 2655, 2656, 2657, 2658, 2659, 8893, 8894, 8895, 8896, 8897, 8898, 8899, 8900, 8907, 8908, 8909, 8910, 8911, 12846, 12847, 12848, 12849, 12850, 12851, 12852, 12853, 12854, 12855, 12856, 12857, 12858, 12859, 12860, 12861, 12862, 12863, 12864, 12865, 12866, 12867, 12868, 12869, 12870, 12871, 12872, 12873, 12874, 12875, 12876, 12877, 12878, 12879, 12880, 12881, 12882, 12883, 12884, 12885, 12886, 12887, 14964, 15863, 19563, 19564, 25577, 29027, 29028, 29029, 29030, 29031, 29032, 29033, 32683, 32684, 32685, 34210, 34211, 34212, 34213, 34214, 34215, 34216, 34217, 51261, 51262, 51263, 51264, 51265, 51266, 51267, 51268, 51269, 51270, 90099, 90100, 90101, 90102, 90103, 90104, 90105, 90106, 90107, 90111, 90112, 90113, 90114, 90115, 106441, 106442, 106443, 106444, 106445, 106446, 106447, 106448, 106449, 106450, 106451, 111318, 111319, 111320, 111321, 111322, 111323, 111324, 111325, 111326, 111327, 111328, 111329, 111336, 111337, 111338, 111953, 111954, 111955, 111956, 111957, 111958, 111988, 111989, 111990, 111991, 111992, 111993, 111994, 111995, 111996, 111997, 111998, 112108, 112109, 113484, 113485, 113486, 113487, 117413, 117414, 117415, 117416, 117421, 117422, 139742, 139743, 139744, 139745, 139746, 139747, 139748, 139749, 139750, 139751, 139752, 139753, 140299, 140300, 140301, 141822, 141823, 141824, 147249, 147250, 147251, 153690, 153691, 153692, 153693, 153694, 153695, 153696, 153697, 153698, 153699, 153700, 155957, 155958, 155959, 155960, 155961, 155962, 155963, 155964, 155965, 155966, 155967, 161641, 161642, 161643, 161644, 161645, 161646, 161647, 161648, 161649, 161650, 168666, 168667, 168668, 168669, 168670, 168671, 168672, 168673, 168674, 168675, 168676, 174343, 176368, 176369, 176370, 176371, 185853, 187836, 187837, 187838, 187839, 187840, 187841, 187842, 187843, 187854, 187855, 187856, 187857, 187858, 187859, 187860, 187861, 187862, 187863, 187864, 187865, 187866, 187867, 187868, 187869, 187870, 187871, 187872, 187873, 187874, 187875, 187876, 187877, 189050, 189051, 189052, 189053, 189054, 189055, 189056, 189057, 189058, 189059, 189060, 189061, 189062, 189063, 189064, 189065, 189066, 189067, 189068, 189069, 189070, 189071, 189072, 189073, 189074, 189075, 200925, 200926, 200927, 200928, 200929, 200930, 200931, 200932, 200933, 200934, 200978, 205168, 205169, 205170, 205171, 205172, 205173, 205174, 205175, 205176, 205177, 205178, 205179, 205180, 206425, 206426, 206427, 210723, 210724, 210725, 214221, 214222, 214423, 214424, 214425, 214426, 214427, 214428, 214429, 214430, 214770};
		result = find_street_street_segments("Dufferin Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {23072, 23073, 23074, 23075, 25046, 25047, 25048, 25049, 25050, 25051, 25052, 25053, 25054, 25056, 41365, 41366, 42075, 42076, 42078, 42079, 42080, 42081, 42082, 42127, 42128, 42365, 42366, 42367, 42368, 42369, 42370, 42371, 42372, 42373, 42374, 42375, 42382, 42383, 43793, 86807, 86809, 86810, 86813, 86814, 86815, 86816, 86818, 86819, 86820, 86821, 86822, 86823, 86824, 86826, 86827, 86828, 86829, 86830, 86831, 86832, 86833, 87065, 87090, 87104, 87142, 87148, 87165, 87186, 87283, 87391, 87457, 87571, 87573, 87636, 87642, 87675, 87701, 87702, 87706, 87708, 104654, 114923, 114930, 115719, 115720, 115735, 115736, 115737, 115738, 115739, 115740, 115741, 115742, 115743, 115744, 115745, 126452, 126455, 126456, 126457, 126458, 126459, 126460, 126461, 126462, 126463, 126464, 126466, 126467, 126479, 128325, 128388, 128410, 128413, 128414, 128415, 128417, 128418, 128423, 128425, 128427, 128429, 128430, 128436, 128437, 128438, 128439, 128440, 128444, 128445, 128447, 128448, 129922, 129923, 129924, 129925, 129926, 129927, 129928, 129929, 129932, 129933, 129934, 129935, 129936, 129937, 129938, 129944, 129945, 129946, 129947, 129948, 129949, 129952, 129953, 129955, 129956, 129957, 129958, 129959, 129960, 129961, 129964, 129965, 129966, 129967, 129968, 129969, 129971, 129973, 129974, 129975, 129976, 129977, 129978, 129979, 129980, 129982, 130980, 138102, 138103, 138104, 138105, 138106, 138107, 138108, 138109, 138110, 138111, 138112, 138113, 138114, 138115, 138116, 138117, 151222, 151224, 151225, 151226, 151227, 151228, 151229, 151230, 163858, 163859, 163860, 163861, 163862, 163863, 163864, 163865, 163866, 163867, 163868, 163869, 163870, 163871, 163872, 163873, 163874, 163875, 163876, 163877, 163878, 163879, 163880, 163881, 163882, 186570, 186571, 191896, 196605, 196606, 200494, 205101, 208200, 208201, 208202, 208203, 208204, 208205, 208206, 208207, 208208, 208209, 208210, 208211, 208212, 208213, 208214, 208215, 208216, 208217, 208218, 208219, 208220, 208221, 208222, 208223, 208224, 208225, 208226, 208227, 208228, 208229, 208230, 208231, 208232, 208233, 208234, 208235, 208236, 208237, 208238, 208239, 208240, 208241, 208826, 208827, 208828, 208829, 208830, 208831, 208832, 208833, 210137, 210138, 210139, 210140, 211241, 211282, 211437, 212174};
		result = find_street_street_segments("Weston Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {158, 159, 160, 161, 7920, 7921, 7922, 7923, 7924, 20652, 20653, 20654, 20655, 20656, 20657, 20658, 20659, 20660, 20661, 20662, 20663, 20664, 20665, 20666, 20667, 25662, 25669, 40782, 40783, 40784, 40785, 40786, 40787, 40982, 40983, 41171, 41172, 41173, 41174, 41175, 54807, 54819, 54820, 54833, 54834, 54835, 54836, 54837, 54838, 54839, 54840, 59470, 59471, 59472, 59473, 59474, 59475, 59476, 59477, 59478, 59479, 59480, 59481, 59482, 59483, 59484, 59485, 59486, 59487, 59488, 59489, 59490, 76964, 76965, 76966, 76967, 76973, 76974, 76975, 76976, 76977, 76980, 76987, 76988, 76989, 76990, 76991, 76992, 76993, 76994, 76995, 76996, 76997, 76998, 77875, 77876, 77877, 77878, 77879, 78845, 78846, 78847, 78848, 78849, 78850, 78851, 78852, 78853, 78854, 78855, 78856, 78857, 78863, 78864, 78865, 78866, 78867, 78868, 78869, 78870, 78871, 78872, 82595, 82596, 82599, 82600, 82604, 82605, 82606, 82607, 82608, 82609, 82611, 82617, 82618, 82619, 83598, 83599, 83600, 83601, 83602, 83603, 83604, 83605, 83606, 83607, 83608, 83609, 83610, 83611, 83612, 83617, 83618, 83619, 83620, 83621, 83622, 83623, 83624, 83627, 83628, 83629, 83630, 83631, 83632, 83633, 84146, 84156, 84157, 84158, 84159, 84160, 84161, 84162, 84164, 84165, 84166, 84167, 84168, 84800, 84802, 84803, 84806, 84807, 84809, 84812, 84856, 84857, 84858, 84859, 84860, 84861, 84862, 84863, 84864, 84868, 84869, 84872, 84873, 84874, 84875, 84876, 84877, 84881, 84882, 84883, 94332, 94333, 94334, 94335, 94336, 94337, 94338, 94339, 94340, 94341, 94342, 94343, 94344, 94345, 94346, 94347, 94348, 94349, 94350, 94351, 94352, 94353, 94354, 94355, 95337, 95338, 95339, 95340, 95352, 95353, 95354, 95355, 95357, 95358, 112892, 112893, 112894, 112895, 112896, 112897, 112898, 113445, 113446, 113447, 113448, 113554, 113555, 113556, 113557, 113558, 113559, 113560, 113564, 113565, 115168, 115169, 115170, 115171, 115172, 115173, 116195, 116196, 117136, 117137, 117138, 117139, 117140, 117141, 133912, 133922, 133923, 133951, 133952, 133960, 133961, 133962, 133963, 133967, 133968, 133969, 133970, 133971, 133972, 133973, 133974, 133975, 133976, 133977, 133978, 133979, 133980, 133981, 133982, 133983, 133987, 133988, 133989, 133990, 133991, 133994, 133995, 133996, 133997, 133998, 133999, 134002, 134003, 134005, 134006, 134009, 134011, 134012, 142495, 142496, 142497, 147257, 147258, 147259, 148003, 148004, 148315, 148316, 148317, 148318, 148319, 154407, 154408, 154409, 154410, 154411, 154412, 154413, 154414, 154415, 154419, 154420, 154421, 154422, 154423, 154424, 154425, 154426, 154427, 154428, 154429, 154430, 154431, 154432, 154433, 154434, 154435, 154436, 156826, 156827, 156828, 156829, 156830, 156831, 156832, 156833, 159682, 159683, 159684, 159685, 162699, 162700, 163053, 181739, 181740, 181741, 181742, 181743, 181744, 181745, 181746, 181747, 181748, 184089, 184090, 184091, 184092, 184093, 184094, 184095, 184096, 184097, 184098, 187207, 187208, 187209, 187210, 187211, 188023, 188024, 188025, 189969, 189970, 189971, 190323, 190324, 190527, 195441, 195442, 195443, 195632, 195633, 195634, 195636, 195637, 200575, 200576, 203836, 207696, 207697, 209430, 209431, 209432, 210338, 210339, 210340, 210341, 210342, 210619, 210620, 210621};
		result = find_street_street_segments("Sheppard Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {800, 1436, 1437, 1438, 29606, 29607, 29608, 39692, 41497, 41498, 41499, 41500, 41501, 41572, 41573, 41574, 41575, 41576, 41577, 41578, 42179, 42180, 42181, 42182, 42183, 42184, 42185, 42186, 65293, 65294, 65295, 65296, 73402, 78089, 78090, 78091, 78092, 78093, 78094, 78095, 78097, 78098, 78099, 78100, 78101, 78102, 78103, 78104, 78105, 78106, 78107, 78108, 78109, 78110, 79293, 79294, 79295, 79296, 79297, 79298, 79299, 79300, 79301, 79302, 79303, 79304, 79305, 79306, 85986, 85987, 86009, 86013, 86014, 86041, 86042, 86044, 86047, 86048, 86059, 86065, 86066, 86082, 86083, 86096, 86097, 86111, 86132, 86141, 86149, 86150, 86153, 86178, 86179, 86180, 86181, 86182, 86184, 86185, 86213, 86217, 86246, 86247, 86256, 86257, 86275, 86278, 86837, 86838, 86839, 86842, 86843, 86844, 86845, 86846, 86847, 86849, 86850, 86852, 86853, 86854, 86855, 86856, 86857, 86858, 86859, 86860, 86861, 86862, 86863, 86864, 86865, 86866, 86867, 86868, 86869, 86870, 86874, 86875, 86877, 86878, 86879, 86880, 86881, 86882, 86883, 86884, 86885, 86886, 86887, 86888, 86889, 86890, 86891, 86892, 86893, 87015, 87057, 87063, 87128, 87129, 87130, 87131, 87407, 87466, 87504, 87641, 87649, 87650, 87703, 87704, 87705, 87707, 87724, 87725, 87726, 87727, 87728, 87777, 87861, 87892, 87963, 87972, 87973, 87974, 87975, 87978, 88042, 88043, 88044, 88045, 88051, 88060, 88061, 88205, 88208, 88209, 88210, 92012, 92013, 92015, 92024, 92025, 92030, 92031, 92032, 92033, 92045, 92046, 92047, 92048, 92049, 92050, 92051, 92052, 92053, 92054, 92055, 92056, 92057, 92118, 92119, 106423, 106424, 106434, 106435, 106436, 106437, 106438, 106439, 106440, 134129, 134130, 138507, 138512, 138514, 138515, 138516, 138517, 138518, 155898, 156707, 156708, 156709, 156710, 156711, 156712, 156868, 156869, 156870, 156871, 156872, 156873, 156874, 156875, 156876, 156877, 156878, 156879, 156890, 159342, 159343, 174344, 174345, 177846, 177847, 177848, 177849, 177850, 177851, 177852, 177853, 177854, 177855, 177856, 177857, 177858, 177859, 177860, 177861, 177862, 177863, 177864, 177865, 180714, 180715, 185694, 198954, 198955, 202117, 203594, 203595, 203596, 203597, 203598, 203599, 203602, 203603, 203613, 203614, 211190, 211191, 211192, 211193, 211194, 214026, 214027, 214089};
		result = find_street_street_segments("Finch Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {693, 694, 1908, 1909, 1910, 1911, 1912, 13292, 13293, 13294, 26757, 26758, 26759, 26760, 26761, 26762, 26763, 26764, 26765, 26766, 26767, 26768, 26769, 26770, 26771, 26772, 26773, 26774, 26775, 26776, 36468, 36469, 36474, 36475, 36477, 36478, 36479, 36480, 36481, 36482, 36483, 36484, 36485, 36486, 36487, 36488, 41154, 41155, 41156, 41157, 41158, 41159, 41160, 41161, 41162, 42274, 42275, 67608, 67609, 67692, 69907, 73395, 73396, 73397, 79328, 79329, 79333, 79334, 79337, 79340, 79341, 79343, 79344, 79345, 79346, 79347, 79348, 79350, 79351, 79352, 79353, 79354, 79365, 81117, 81118, 81119, 81120, 81121, 81122, 81123, 81223, 81224, 81233, 81240, 81244, 81248, 81249, 81258, 81259, 81260, 81261, 81328, 81329, 81330, 81331, 81337, 81338, 81340, 81341, 81342, 81343, 81344, 81345, 81346, 81349, 81350, 81351, 81352, 81354, 81357, 81358, 81360, 81361, 81362, 81363, 81364, 81365, 81366, 81367, 81368, 81369, 81370, 81371, 81372, 81373, 81374, 81710, 81712, 81713, 81714, 81715, 81717, 81718, 81719, 81720, 81721, 81722, 81723, 81724, 81729, 81730, 81731, 81732, 81733, 81734, 81735, 81736, 81737, 81738, 81739, 81740, 81741, 81742, 81743, 81744, 81745, 81746, 81747, 81749, 81750, 81751, 81752, 81756, 81782, 81785, 81786, 81794, 81795, 81796, 81797, 81798, 81799, 81800, 81801, 85722, 85723, 85724, 85725, 89137, 89138, 89139, 89140, 89141, 89142, 89143, 89144, 89145, 89146, 89147, 89148, 89149, 89150, 89151, 89152, 89153, 89154, 89155, 89156, 89157, 89158, 89159, 89160, 89161, 89162, 89163, 89164, 89165, 91981, 91982, 91989, 91990, 99831, 99832, 99833, 99834, 99835, 99836, 99837, 99838, 99843, 99844, 99845, 99846, 99847, 99848, 99849, 99850, 99851, 99852, 99853, 99854, 99855, 111304, 111305, 111306, 111307, 111308, 111309, 111310, 113415, 113416, 113417, 113418, 113419, 113420, 113421, 113422, 113655, 113656, 113657, 113658, 113659, 113660, 113661, 113662, 113663, 113664, 113665, 113666, 113667, 116844, 116845, 116846, 116847, 116848, 116849, 116850, 122274, 122275, 122278, 122281, 122282, 122283, 122284, 122285, 122287, 122288, 122289, 122291, 122317, 122318, 122319, 132333, 132338, 132339, 134368, 134369, 138501, 138508, 138509, 138510, 138511, 142348, 142350, 142351, 142352, 142354, 152098, 152099, 152100, 152101, 152102, 152103, 152105, 152106, 152107, 152108, 152109, 152110, 152111, 152112, 152113, 152114, 152115, 152116, 152117, 152119, 152120, 152121, 152122, 152124, 152125, 152126, 152127, 152130, 152131, 152133, 152134, 152135, 152137, 152138, 152139, 152141, 152143, 152144, 152145, 152146, 152147, 154037, 154038, 154039, 158622, 161520, 161521, 161522, 161523, 161524, 161525, 161526, 161527, 161528, 163602, 163603, 165477, 165478, 167616, 167617, 167618, 167619, 167620, 167621, 167622, 167629, 167630, 167631, 167632, 167633, 167634, 167635, 167636, 167637, 177838, 180720, 185082, 185083, 185084, 185085, 185086, 186264, 186265, 186266, 186267, 186268, 186269, 187675, 187676, 187677, 187678, 187679, 187680, 187743, 187744, 187745, 187896, 187897, 187898, 187899, 187900, 187916, 187917, 187918, 187919, 187920, 187921, 187922, 187925, 187926, 188054, 188055, 189030, 189031, 189032, 189033, 189034, 189035, 189036, 189037, 189888, 189889, 189890, 189891, 190179, 190180, 190181, 190182, 190183, 190184, 190185, 190186, 190187, 190188, 190189, 191083, 191084, 191085, 195299, 195300, 195301, 195302, 195303, 195304, 196611, 196612, 196613, 200725, 200726, 200727, 203031, 203032, 203033, 203034, 203035, 203036, 203037, 203038, 203097, 203098, 203099, 203100, 203101, 203107, 204883, 204884, 206113, 207687};
		result = find_street_street_segments("Steeles Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {2391, 8890, 8891, 8892, 19772, 19773, 21717, 21720, 21721, 21722, 21725, 21726, 21727, 21728, 21731, 21732, 21733, 21734, 21735, 21761, 21762, 21763, 21764, 21765, 42362, 42363, 42364, 106452, 106453, 106454, 106455, 106456, 106457, 117906, 117907, 117910, 119630, 119631, 119632, 147600, 147601, 151695, 151696, 151699, 151701, 151702, 151703, 154437, 154438, 154439, 154440, 154441, 154442, 154443, 154444, 166672, 174352, 214769};
		result = find_street_street_segments("William R. Allen Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {440, 441, 442, 443, 444, 445, 446, 447, 450, 451, 452, 453, 454, 455, 456, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 1033, 1034, 10123, 10124, 10125, 10126, 10127, 10128, 14649, 15830, 15831, 15832, 15835, 17156, 26807, 26816, 26831, 26832, 39363, 39364, 39365, 40721, 40722, 40723, 45136, 45137, 46843, 46844, 46845, 46846, 46847, 46848, 62774, 63894, 64794, 65303, 73512, 73557, 73558, 92879, 92880, 92881, 99134, 111496, 111497, 111498, 111499, 111500, 111501, 111502, 111503, 111504, 111509, 111635, 111636, 116252, 116253, 116254, 132430, 132433, 132434, 132435, 132436, 132565, 132566, 132567, 132568, 132569, 132570, 134510, 140284, 140285, 140303, 140304, 140305, 141612, 141613, 141614, 141615, 141616, 141617, 141618, 155711, 155712, 159398, 159399, 159400, 159401, 159402, 159403, 159404, 159405, 159406, 159407, 159711, 159712, 159713, 159714, 159715, 159716, 159717, 165006, 165007, 165008, 165009, 165010, 165011, 176414, 176415, 178926, 178927, 178928, 178929, 178930, 178931, 178932, 178933, 183873, 184169, 184170, 186690, 186691, 186692, 186693, 186694, 186695, 186696, 186697, 186698, 186699, 186700, 186701, 186702, 186703, 186704, 186705, 186706, 186707, 186708, 186709, 186710, 186711, 186712, 186713, 186714, 186715, 186716, 186717, 186718, 186719, 186720, 186721, 186722, 187254, 187255, 187256, 187257, 187258, 187259, 187260, 187261, 187262, 187592, 187593, 188237, 188238, 188239, 188240, 188241, 188244, 188245, 188246, 188247, 188248, 188249, 188261, 188262, 188271, 188272, 188273, 188274, 188275, 188276, 188277, 188278, 188279, 188280, 188281, 188282, 188299, 188300, 188301, 188302, 188303, 188304, 188305, 188306, 188345, 188346, 188347, 188348, 188349, 188350, 188351, 188352, 188353, 188354, 188369, 188370, 188371, 188372, 188373, 188374, 188375, 188381, 188382, 188386, 188387, 188388, 188389, 188390, 188391, 201746, 201747, 201748, 201749, 201750, 201751, 201752, 201753, 201754, 201755, 201756, 201757, 201758, 201759, 205279, 205280, 205281, 205282, 205283, 205284, 205285, 207512, 207513, 207514, 207515, 207516, 207517, 207518, 207519, 207520, 207521, 207522, 207523, 207524, 207525, 207526, 207925, 208092, 208093, 208094, 208095, 208096, 208097, 208098, 208099, 208100, 208101, 208657, 208658, 208659, 208660, 208661, 208662, 208663, 208664, 208665, 208666, 208667, 208668, 208669, 208670, 208671, 208672, 208673, 208674, 208675, 208676, 208677, 208678, 208679, 208680, 208681, 208682, 208683, 208684, 208685, 208686, 208687, 208688, 208689, 208690, 208691, 208692, 208693, 208694, 208695, 208696, 208697, 208698, 208699, 208700, 208701, 208702, 208703, 208704, 208705, 208706, 208707, 208708, 208709, 211566, 211567, 211568, 211569, 211570, 214705};
		result = find_street_street_segments("Lake Shore Boulevard West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {24810, 34459, 34460, 34461, 34462, 34468, 34469, 34470, 34471, 34472, 62747, 62748, 62749, 62750, 62751, 62752, 62753, 62754, 62755, 62756, 62757, 62758, 133152, 133154, 133171, 133172, 133173, 133178, 133179, 133180, 133182, 133183, 133184, 133185, 133186, 133187, 133192, 133195, 133196, 133198, 133201, 133213, 133215, 133221, 133222, 133223, 133224, 133225, 133226, 133232, 133233, 133234, 133245, 133246, 133247, 133249, 133251, 133252, 133255, 133256, 133258, 133264, 133269, 133270, 133280, 133281, 133287, 133299, 133300, 133305, 133314, 133315, 133316, 133317, 133319, 133321, 133322, 133323, 133333, 133335, 133336, 133338, 133341, 133343, 133344, 133345, 133348, 133350, 133352, 133353, 133354, 133355, 133368, 133369, 133370, 133377, 133378, 133380, 133381, 133382, 133385, 133388, 133393, 133394, 133395, 133396, 133401, 133427, 133432, 133435, 134945, 134947, 135377, 135378, 135379, 135380, 135409, 135410, 135411, 135412, 140801, 140802, 140803, 140811, 140814, 140815, 140819, 140820, 142360, 142361, 142362, 142363, 142364, 142365, 142366, 142368, 142369, 142370, 142371, 142373, 142374, 142375, 142376, 142377, 142378, 142379, 142380, 142381, 143070, 143071, 143073, 143082, 143083, 143084, 143085, 143089, 143106, 143107, 143108, 143109, 143110, 143140, 143141, 143142, 143143, 161596, 161597, 161598, 182168, 182185, 182186, 182187, 182188, 182189, 182190, 182191, 182192, 182193, 182194, 182195};
		result = find_street_street_segments("Erin Mills Parkway");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {13213, 13214, 13215, 13216, 13217, 13218, 13219, 13337, 13338, 22750, 22751, 26403, 26404, 26405, 27304, 27305, 27306, 27307, 27308, 27309, 27310, 28925, 78286, 78287, 78288, 78289, 78290, 78291, 78355, 78356, 78357, 78358, 78360, 78361, 78362, 78363, 78364, 78365, 78366, 78367, 78837, 78838, 78839, 78840, 78841, 78905, 78907, 78908, 78909, 78910, 78911, 78912, 78913, 78914, 78915, 80403, 80404, 80405, 80406, 80410, 80411, 80415, 80416, 80417, 82791, 82792, 82793, 82794, 82795, 82796, 82797, 82798, 82799, 82800, 82801, 82802, 82803, 82804, 82805, 82806, 82807, 82808, 82809, 82810, 85687, 85688, 85692, 85693, 85694, 85695, 85696, 85697, 85698, 85699, 85700, 85701, 85702, 85703, 92503, 111300, 111301, 111348, 111349, 111350, 111351, 111352, 111353, 111354, 111355, 111356, 111357, 116249, 116250, 116318, 116319, 116320, 116321, 116323, 116328, 116334, 116335, 116336, 116337, 144218, 144219, 177841, 191531, 191839, 191840, 195356, 195357, 195358, 195359, 195360, 195361, 195545, 195546, 195564, 195565, 195574, 195575, 195576, 195577, 195578, 195579, 195580, 195581, 195582, 195583, 195585};
		result = find_street_street_segments("Morningside Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {3669, 3710, 3711, 3712, 3713, 3714, 3715, 3716, 16239, 16240, 16241, 16242, 16243, 16244, 16245, 16246, 16247, 19870, 19871, 19872, 19873, 29003, 29004, 37606, 37607, 37608, 37609, 37610, 37611, 37612, 37613, 37614, 37615, 37616, 37617, 37618, 37619, 37620, 38111, 38112, 38113, 41240, 53107, 53108, 75526, 79776, 79777, 79778, 79779, 79791, 79792, 79793, 79794, 79795, 79840, 79841, 79842, 79843, 79844, 79845, 79846, 79847, 81205, 81206, 81207, 81208, 81209, 81210, 81211, 81212, 81213, 81214, 81215, 81216, 81217, 81218, 81219, 81220, 81221, 81222, 81225, 81226, 81227, 81228, 81229, 81230, 81231, 81232, 81234, 81235, 81236, 81237, 81238, 81239, 81241, 81242, 81243, 81245, 81246, 81247, 81250, 81251, 81252, 81253, 81254, 81255, 81256, 81257, 81262, 81273, 81274, 84789, 84790, 84791, 84792, 84793, 84794, 84795, 84797, 84798, 84799, 84801, 84804, 84805, 84808, 84810, 84811, 94607, 94608, 94609, 94610, 94611, 94612, 94613, 94614, 94615, 94616, 94617, 94618, 94619, 94620, 94622, 95819, 95821, 95822, 95823, 95824, 95825, 95828, 96065, 96067, 96070, 96073, 96075, 96077, 96078, 96079, 96081, 96083, 96084, 96085, 96088, 96089, 96091, 96092, 96093, 96095, 96096, 96098, 96100, 96101, 96102, 96103, 96104, 96105, 96107, 96108, 96109, 96110, 96111, 96112, 96113, 96114, 96115, 96116, 96117, 98392, 98612, 113497, 113498, 115441, 115442, 115443, 115444, 115445, 115446, 115447, 115448, 115449, 115450, 115453, 115454, 115455, 115456, 115465, 115467, 115468, 115469, 115470, 115542, 115543, 115544, 115553, 115554, 115555, 115556, 115557, 115558, 115559, 115560, 115561, 120827, 120828, 120829, 120830, 120831, 120832, 120835, 130046, 130063, 130292, 130444, 130620, 130625, 130652, 130710, 130764, 131469, 131470, 131471, 131472, 142513, 142514, 145108, 145111, 145112, 145113, 145114, 145115, 145116, 145119, 145120, 145121, 145122, 145123, 145124, 145125, 146977, 156303, 156304, 156305, 156306, 157598, 157599, 171397, 171398, 171399, 171400, 171401, 171402, 171403, 171404, 171405, 171406, 183810, 183811, 183812, 183813, 183814, 186035, 186036, 191512, 191513, 194964, 195759, 197804, 198481, 198482, 198483, 198484, 198485, 198486, 198487, 198488, 198489, 198490, 199610, 199611, 206296, 206297, 208155, 210383, 210384, 210406, 210407, 210408, 210409, 210410, 211487, 211488, 211489, 214711};
		result = find_street_street_segments("McCowan Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, streets_intersections_functionality) {
		std::vector<unsigned> result;
		std::vector<unsigned> expected_result;
		
		expected_result = {49, 50, 80, 85, 94, 101, 102, 103, 104, 105, 106, 107, 108, 609, 659, 1278, 1332, 1648, 1725, 1791, 1828, 1859, 1864, 1896, 2298, 2522, 2956, 2972, 2992, 3023, 3051, 3369, 3482, 5305, 5318, 5335, 5348, 5367, 5402, 5410, 5610, 5616, 5644, 5656, 5708, 5794, 5817, 6245, 6250, 6252, 6254, 6271, 6281, 6282, 6283, 6315, 6316, 6317, 6318, 6319, 6321, 6322, 6324, 7194, 7578, 7847, 7890, 8081, 8089, 8096, 8101, 8105, 8122, 8131, 8142, 8158, 8161, 8169, 8170, 8171, 8172, 8184, 8185, 8327, 8328, 8336, 8339, 8340, 8341, 8538, 8545, 9289, 9528, 9535, 9541, 9799, 10538, 11357, 11395, 11432, 11668, 11669, 11670, 11671, 11672, 11674, 11679, 11681, 11683, 11707, 11710, 12466, 12605, 12638, 13033, 13128, 13227, 13250, 13263, 13265, 13291, 13317, 13320, 13347, 13358, 13510, 13514, 14256, 14261, 14262, 14263, 14264, 14265, 14659, 14666, 14667, 14668, 15781, 15792, 15796, 15804, 15823, 15824, 15829, 15830, 15837, 15843, 15851, 16648, 16933, 16945, 16960, 17142, 17337, 17462, 17698, 17712, 19328, 19329, 19397, 19459, 19460, 19496, 19600, 19677, 19694, 20046, 22348, 22380, 22387, 22432, 22443, 22983, 23156, 23170, 23175, 23176, 23177, 23178, 23179, 23210, 23211, 23212, 23213, 23214, 26063, 26384, 26657, 26661, 27455, 27809, 27810, 27811, 27812, 27813, 28396, 28486, 28487, 28489, 28492, 28571, 28905, 28906, 28924, 29664, 29665, 29703, 29708, 29725, 29731, 29962, 31222, 31612, 32489, 32947, 33744, 35740, 35741, 37171, 37194, 37195, 37196, 37229, 37230, 37231, 37232, 37233, 37234, 38108, 38109, 38110, 38115, 39683, 39684, 39685, 39698, 39699, 40219, 40414, 46819, 46820, 48650, 48651, 48820, 48934, 48937, 49522, 50824, 50825, 50826, 50827, 50828, 50829, 50840, 50888, 54000, 54001, 54002, 54003, 54004, 61436, 61454, 61858, 61973, 61974, 61975, 63688, 64103, 64104, 64105, 64538, 64872, 66277, 66778, 66880, 66881, 67317, 67589, 67731, 67774, 67812, 68302, 68653, 68654, 68728, 69382, 70078, 70079, 70110, 74007, 74075, 74076, 74077, 74078, 74935, 74936, 74937, 74950, 74951, 74952, 74953, 74954, 74955, 74956, 74957, 76700, 76746, 76751, 82511, 84287, 84341, 84344, 84345, 84346, 84347, 84348, 84354, 84355, 85873, 86640, 86641, 86642, 86643, 86644, 86645, 86646, 86647, 86648, 86649, 86650, 86651, 86652, 86653, 86654, 86655, 86656, 86657, 86658, 86659, 86660, 86661, 86662, 86663, 86664, 86665, 86666, 86667, 86699, 86700, 86701, 86732, 86733, 86734, 86735, 86736, 89429, 89447, 89585, 89611, 89614, 89625, 89626, 89627, 89628, 89629, 89630, 89631, 89632, 89633, 89634, 89635, 89639, 89640, 89648, 89649, 89650, 89651, 89652, 89653, 89654, 89655, 89659, 89660, 89661, 89662, 89663, 89664, 89665, 89666, 89669, 89670, 89673, 89674, 89675, 89676, 89677, 89715, 89716, 89717, 89718, 89719, 89725, 89726, 89729, 89730, 89732, 89733, 89734, 89735, 89736, 96439, 96442, 96448, 98357, 98375, 98376, 99599, 99638, 99756, 99757, 99775, 100004, 100010, 100020, 100022, 100023, 100024, 100028, 100032, 100176, 100412, 101212, 101213, 101216, 101217, 101252, 101253, 101254, 101255, 101256, 101271, 101272, 101273, 101274, 101275, 101276, 101277, 101278, 101279, 101280, 101285, 101286, 101290, 101291, 101292, 101293, 101294, 102007, 102036, 102137, 102506, 102507, 102508, 102509, 102951, 102952, 102953, 102954, 104223, 108413, 108415, 108418, 108419, 111729, 111730, 111731, 111733, 111734, 111735, 111736, 111738, 111739, 111740, 111741, 111744, 111748, 111751, 111752, 111927, 111931, 111932, 111933, 111942, 111943, 111945, 111946, 111953, 111965, 111966, 111968, 111969, 111972, 111973, 111974, 111978, 111979, 111989, 111996, 111997, 111998, 112003, 112008, 112009, 112010, 112011, 112012, 112013, 112014, 112015, 112016, 112017, 112018, 112022, 112023, 112031, 112032, 112033, 112034, 112035, 112036, 113783, 113784, 113785, 113786, 113787, 113788, 113841, 113879, 113880, 113881, 113882, 113883, 113884, 113885, 113886, 113887, 113890, 113891, 113893, 113907, 113908, 113909, 113910, 113911, 113918, 113919, 113920, 113922, 113923, 113924, 113926, 113927, 113932, 113933, 113934, 113936, 113940, 113941, 113942, 113948, 113949, 113950, 115532, 115533, 115731, 115732, 115735, 117806, 117807, 119754, 120941, 120942, 120943, 121587, 124049, 128282, 128283, 129112, 129178, 129284, 129285, 129286, 129287, 129288, 129710, 129715, 129722, 129724, 129726, 129730, 130288, 130995, 131135, 131136, 131250, 131579, 131835, 131841, 132013, 132015, 132036, 132228, 133422, 133424, 133428, 133446, 133453, 134861, 134865, 138698, 138748, 138876, 138879, 139970, 141894, 141895, 141896, 142145, 142149, 142727, 142790, 142791, 142792, 142795, 142796, 142797, 142798, 142810, 142811, 142812, 142813, 142814, 142815, 142816, 142817, 142818, 142838, 142839, 142840, 142841, 142842, 142971, 144195, 144196, 144781, 144878, 145951, 147593, 148739, 148742, 148743, 148744, 148745, 148746, 148747, 148748, 148749, 148750, 149694, 149697, 149949, 149963, 149985, 150112, 150113, 150114, 150115, 150116, 150117, 150118, 150215, 150216, 150217, 150218, 150552, 152785, 152952, 152954, 152963, 152964, 153251, 153252, 155031, 155032, 155033, 155034, 155035, 155806, 155807, 155814, 155815, 155816, 156709, 157559, 159364, 159365, 159366, 159367, 159370, 160050, 160433, 160434, 160435, 160436, 160437, 160438, 160439, 161903, 162449, 162450, 162451, 162452, 162536, 162537, 163419, 163946, 163947, 164161, 164162, 164163, 164164, 164165, 164166, 164167, 164196, 164197};
		result = find_all_street_intersections("Yonge Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {794, 803, 804, 805, 809, 811, 1648, 1649, 1650, 4203, 4204, 4205, 4206, 4207, 4208, 4209, 4210, 4211, 4962, 4971, 6574, 6575, 6605, 6606, 6607, 6608, 6609, 6610, 7379, 8901, 10839, 10840, 10845, 10848, 10911, 10912, 10913, 10914, 10915, 10916, 12005, 12006, 12013, 12020, 12039, 12056, 12057, 12066, 12254, 12265, 12266, 12347, 12350, 12362, 13249, 14893, 17036, 17037, 17042, 17052, 17063, 17074, 17075, 17081, 17558, 17563, 17655, 17662, 19579, 19580, 19589, 21099, 21972, 22009, 23103, 23104, 23105, 23106, 23107, 23290, 23406, 23407, 23458, 23459, 23460, 23461, 23462, 23483, 23484, 23485, 23486, 23613, 24888, 24906, 24908, 24910, 24921, 24922, 24923, 25623, 26623, 26626, 26630, 26653, 26654, 31440, 31441, 31442, 31443, 34054, 34055, 34108, 34109, 34170, 34786, 35234, 35235, 35236, 35237, 35238, 35239, 35240, 35241, 35242, 35243, 35244, 35245, 35246, 35247, 35248, 35249, 35250, 35251, 35252, 35660, 35662, 35663, 35664, 35665, 35666, 38468, 38487, 40143, 40308, 40749, 40752, 41044, 41045, 41046, 41047, 41468, 41509, 41510, 41511, 41512, 41513, 42016, 42412, 42738, 42739, 42740, 57323, 57324, 57325, 57348, 57349, 57993, 57994, 58000, 61538, 61539, 61540, 61541, 61542, 71879, 72294, 72295, 72310, 72409, 72449, 72451, 72452, 72453, 79699, 79701, 85517, 85519, 85520, 85521, 85522, 85524, 85525, 85526, 85527, 85528, 85529, 85530, 85531, 85532, 85533, 85534, 85535, 85536, 85542, 85543, 85544, 85545, 85546, 85547, 85548, 85549, 85550, 85551, 85552, 85553, 85554, 85562, 85563, 85564, 85572, 85573, 85574, 85575, 85576, 85577, 85578, 85580, 85581, 85583, 85584, 85585, 85601, 85605, 85606, 85608, 85609, 85610, 85611, 85612, 85613, 85614, 85615, 85617, 85618, 85619, 85621, 85624, 85625, 85626, 85627, 85628, 85629, 85630, 85633, 85635, 85639, 85640, 96350, 96351, 96355, 96366, 96367, 96370, 96371, 96372, 96380, 96407, 96410, 96411, 96412, 96414, 96415, 100064, 100084, 100087, 100088, 100089, 100090, 101501, 102411, 102585, 103084, 103101, 103104, 103106, 105955, 108515, 113392, 113393, 113394, 113395, 113396, 113397, 113398, 113401, 113402, 113403, 113404, 115207, 115208, 115209, 115210, 115674, 115676, 116434, 116538, 116539, 116540, 116541, 118359, 118360, 119051, 119071, 119077, 122291, 122292, 122293, 122294, 122295, 122296, 122297, 122298, 122299, 122300, 122301, 122302, 122303, 122304, 122305, 122306, 122307, 122308, 122309, 122310, 122311, 122312, 122313, 122314, 122315, 122316, 122317, 122318, 122319, 122320, 122321, 122322, 122323, 122324, 122325, 122326, 122327, 122328, 122329, 122372, 126384, 126387, 126605, 127419, 127422, 127423, 127426, 127432, 127742, 127747, 128349, 128350, 128352, 129651, 130135, 130292, 130525, 130526, 130527, 130528, 130529, 130530, 130531, 130532, 130533, 130534, 130535, 130536, 130537, 130538, 130539, 130540, 130605, 130608, 130609, 130610, 130611, 130612, 130790, 131348, 131349, 132207, 132208, 132209, 132210, 132211, 132212, 132213, 132214, 132215, 134630, 134631, 134632, 141701, 141705, 142485, 142504, 142568, 142569, 142570, 142571, 142572, 142573, 142574, 142591, 142592, 142593, 142654, 145997, 145998, 146554, 146561, 146562, 146571, 146572, 146733, 146734, 146735, 147353, 147354, 148149, 148152, 148153, 148154, 148155, 148156, 148162, 148163, 148179, 148260, 148376, 148377, 148378, 148379, 150623, 150624, 151459, 151464, 151922, 151931, 151972, 153560, 154506, 158020, 158025, 158034, 158363, 159850, 159851, 159852, 162848, 162861, 162863, 162864, 163420, 163421, 163423, 163444, 163506};
		result = find_all_street_intersections("Eglinton Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1295, 1296, 1303, 1304, 1305, 1320, 1327, 1796, 3050, 3066, 5328, 5386, 5720, 5721, 5722, 5790, 7811, 7819, 8542, 8552, 14268, 16659, 23151, 23152, 23153, 23159, 23160, 23161, 23162, 23171, 23172, 23173, 23174, 23190, 25634, 27814, 27815, 27816, 27901, 27911, 27945, 31942, 31948, 32463, 32464, 32465, 40201, 40411, 40412, 40413, 45965, 46816, 50843, 58107, 58110, 58111, 58112, 58113, 58114, 58115, 58116, 58117, 61802, 63371, 63372, 63373, 63374, 63375, 71150, 71151, 71152, 96010, 96041, 96076, 96077, 96078, 99600, 99601, 100170, 100171, 100172, 100173, 101365, 107130, 117267, 117268, 117269, 117270, 117913, 120903, 120904, 124288, 127562, 131015, 144099, 144100, 144101, 144102, 144777, 144778, 147304, 148548, 148559, 148560, 148561, 148562, 148592, 148594, 150469, 150470, 150471, 150472, 150473, 150474, 150479, 150994, 151756, 151757, 153561, 154066, 154067, 154264, 154265, 154266, 155878, 155879, 155881, 163049, 164420};
		result = find_all_street_intersections("Bay Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {959, 964, 1249, 1250, 1561, 1698, 1699, 1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713, 1714, 2298, 2359, 2360, 2361, 2362, 2363, 2381, 2399, 2424, 2462, 2489, 2507, 3044, 3199, 3224, 3251, 3285, 3315, 3347, 3348, 5438, 5586, 5853, 6939, 6940, 6941, 6942, 6993, 7004, 7005, 7006, 7007, 7008, 7009, 7010, 7603, 7617, 7655, 7669, 7678, 7692, 7855, 7871, 7982, 7985, 7990, 7998, 8009, 8696, 8803, 8806, 8807, 8811, 8820, 8821, 8824, 8826, 8992, 8993, 9060, 9065, 9775, 9776, 9779, 10345, 10348, 10620, 10621, 10622, 10623, 10624, 11099, 11103, 11113, 11130, 13547, 13586, 13638, 13668, 15455, 15462, 15515, 15545, 15550, 16096, 16103, 16105, 16109, 16112, 16116, 16117, 16459, 16531, 16532, 16533, 16534, 16535, 16587, 16612, 16613, 16631, 16640, 16888, 17167, 17168, 17169, 17170, 17171, 17379, 17648, 18347, 18354, 18470, 18475, 20851, 20853, 20856, 20860, 20879, 20888, 20894, 21825, 21828, 21840, 21895, 21916, 21921, 22072, 22171, 23162, 23681, 23771, 23922, 28096, 28648, 28650, 28661, 28998, 29407, 29408, 30203, 33714, 36063, 36064, 36065, 36066, 37839, 37840, 37844, 37845, 37854, 37964, 37994, 39918, 40762, 40765, 40769, 40770, 40772, 40777, 40780, 40784, 40816, 40817, 41516, 41517, 41518, 41519, 41520, 41521, 41522, 41523, 41524, 41646, 41804, 43247, 43250, 43259, 43524, 45069, 45070, 45253, 45254, 47858, 47880, 48012, 49004, 49023, 49027, 49071, 49234, 49240, 57314, 58094, 58095, 58097, 60674, 60903, 60905, 62220, 63089, 63090, 70364, 70365, 70366, 70367, 70368, 70369, 70370, 70371, 70372, 70373, 70374, 70532, 70533, 70932, 72116, 72117, 72118, 83343, 83352, 83358, 83359, 83389, 83390, 83392, 83453, 83456, 83482, 83520, 83521, 83522, 83523, 83524, 83525, 83526, 83527, 83529, 83530, 83531, 83532, 83533, 83535, 83536, 83537, 83538, 83539, 83540, 83543, 83552, 83560, 83593, 83594, 83595, 83596, 83844, 83845, 83873, 83875, 83876, 83877, 83878, 83879, 83882, 85055, 85064, 85067, 85069, 88123, 92943, 92944, 92945, 92946, 92947, 92948, 92949, 92951, 92952, 92953, 92954, 92955, 93978, 93985, 93986, 93987, 93989, 93991, 93992, 93993, 93994, 93995, 93996, 93997, 93998, 93999, 94000, 94001, 94002, 94604, 94841, 94856, 95049, 97130, 97133, 97134, 97135, 97217, 97246, 97260, 101618, 101624, 101634, 101656, 101687, 102457, 102459, 102460, 104162, 104553, 105223, 105232, 105234, 105235, 105394, 111309, 111332, 112451, 112452, 113729, 116022, 116023, 116026, 116027, 116028, 116029, 117158, 117288, 117289, 117301, 117328, 119471, 119472, 119473, 119474, 119603, 119612, 119622, 120185, 121942, 121943, 121944, 121949, 121951, 121952, 121960, 121961, 121962, 121963, 121964, 121965, 121971, 121973, 121978, 121980, 121985, 121986, 121987, 122005, 123659, 123664, 123690, 123691, 123692, 128255, 128617, 132943, 132944, 132945, 132946, 132947, 135272, 135273, 135274, 135275, 135276, 135780, 137537, 137550, 137859, 141219, 141220, 141221, 142947, 146910, 147904, 147905, 147906, 147915, 147916, 147917, 147941, 147942, 147943, 147944, 147945, 149201, 150246, 151583, 151584, 151755, 151758, 151759, 151760, 151761, 151998, 151999, 152000, 152001, 152002, 152003, 152004, 152005, 152006, 152007, 152008, 152009, 152010, 152011, 152012, 153661, 153662, 153688, 153689, 153690, 153692, 153693, 153696, 158349, 158350, 158351, 159677, 159678, 159679, 159680, 159681, 159682, 159683, 159684, 159685, 159686, 159687, 159688, 159689, 159690, 159691, 159692, 159693, 159694, 159695, 159696, 160894, 161363, 161492, 161493, 162822, 162823, 162897, 162898, 162900, 162901, 163028, 163029, 163030};
		result = find_all_street_intersections("Dundas Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {959, 960, 961, 962, 963, 1338, 1914, 1957, 1982, 1993, 2037, 2041, 2081, 2082, 2169, 2170, 2391, 2392, 2425, 2449, 2450, 2502, 3023, 3120, 3123, 3124, 3129, 3138, 3192, 3214, 3288, 5720, 6889, 6962, 6963, 6964, 6965, 6966, 7014, 7028, 7609, 7610, 11126, 11141, 11143, 11146, 11174, 11175, 11659, 12033, 13552, 13558, 13579, 13587, 13614, 13627, 13651, 13666, 13822, 15444, 15459, 15464, 16955, 17370, 17653, 17688, 17703, 17705, 23831, 45919, 45920, 45921, 45922, 45960, 45961, 45962, 45963, 45964, 80366, 80401, 80416, 88117, 98643, 98644, 98645, 98646, 98647, 98648, 98649, 98650, 98651, 98652, 98653, 98654, 98655, 98656, 98657, 98658, 98659, 98660, 98661, 98662, 98663, 98664, 98665, 98666, 98667, 117960, 131798, 160098, 160099, 160100, 160101, 160102, 160103, 160104, 160105, 162225, 162226, 162227, 162228, 162229, 162230, 164192, 164193, 164194, 164195};
		result = find_all_street_intersections("College Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {476, 477, 478, 479, 480, 481, 1342, 2469, 2512, 2514, 2955, 5438, 5439, 5440, 5441, 5442, 5443, 5444, 5791, 6360, 6362, 6998, 7004, 7011, 7012, 7013, 7867, 7965, 7967, 7968, 7969, 7970, 9555, 11649, 16891, 16892, 16893, 16894, 16895, 16896, 16897, 16898, 16899, 17703, 17705, 17706, 17707, 23487, 23488, 23489, 23490, 27899, 27900, 45918, 58149, 63377, 63378, 63379, 70653, 70654, 70655, 70656, 70657, 72998, 72999, 73000, 73001, 73002, 73003, 73004, 115529, 115530, 115531, 115699, 133213, 133214, 133215, 152131, 152132, 152133, 152134, 152135, 152136, 158369};
		result = find_all_street_intersections("University Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {435, 436, 437, 438, 439, 440, 913, 914, 915, 916, 1377, 1479, 1482, 1696, 1697, 1896, 1937, 1944, 1949, 1977, 2020, 2059, 2072, 2073, 2098, 2117, 2118, 2153, 2180, 2187, 2200, 2203, 2825, 2844, 5385, 5699, 6738, 6744, 6757, 6761, 7854, 7855, 7856, 7863, 7868, 8386, 8423, 8436, 8565, 8695, 8713, 8986, 8987, 9188, 9238, 9851, 9894, 9899, 9916, 9917, 9989, 13561, 13567, 13612, 15466, 15474, 16064, 16065, 16066, 16067, 16068, 16069, 16070, 16071, 16072, 16073, 16074, 16075, 16076, 17387, 18001, 18002, 18003, 18004, 18005, 18006, 18007, 18008, 18009, 18086, 18089, 18119, 18350, 18432, 19078, 19088, 20070, 20403, 20827, 21766, 21767, 21775, 21776, 21796, 21797, 21806, 21813, 21868, 21917, 21925, 22856, 23499, 23521, 23537, 23558, 27814, 28225, 29226, 29227, 30199, 31945, 31953, 33647, 37134, 37150, 37151, 37824, 39758, 39759, 39944, 39945, 40810, 40811, 40812, 42689, 42715, 42719, 42725, 45381, 45382, 45383, 45398, 45924, 45925, 46020, 46021, 46022, 46023, 57493, 57499, 57500, 57501, 58027, 58089, 58090, 58091, 58092, 58093, 58096, 58097, 61010, 61018, 61034, 61393, 63083, 63084, 63085, 63086, 70817, 81957, 81966, 81969, 81977, 82168, 82169, 82170, 82171, 82172, 82175, 82178, 82179, 82180, 82181, 82183, 82184, 82185, 82186, 82187, 82190, 82191, 82192, 82193, 82194, 82195, 83491, 83497, 83504, 83505, 83563, 83564, 83565, 83566, 83586, 83587, 84579, 84582, 84723, 84726, 85053, 85112, 85122, 85132, 85166, 92846, 92847, 92848, 92849, 92850, 92853, 92854, 92855, 92856, 92857, 92858, 92859, 92860, 92861, 92862, 92863, 92864, 92869, 92871, 92872, 100773, 101677, 101686, 101687, 101688, 102760, 102826, 102827, 102828, 117994, 120091, 124933, 130353, 130354, 130355, 130356, 130357, 130358, 130359, 130360, 133270, 133271, 133272, 133273, 133274, 133275, 133276, 133277, 133278, 133279, 133280, 135672, 149008, 149009, 150425, 150426, 151193, 151744, 151745, 151746, 151747, 151773, 151775, 152615, 154996, 154997, 154998, 155041, 155042, 155043, 158348, 159099, 162456, 162457, 162894, 164300, 164319, 165076, 165077, 165078};
		result = find_all_street_intersections("Bloor Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {432, 433, 434, 3551, 3586, 3598, 3599, 3745, 4104, 4116, 4117, 4124, 4177, 4197, 4286, 4287, 4288, 4289, 4290, 4291, 4292, 4622, 4627, 4796, 4800, 5131, 5151, 5874, 5877, 5881, 5882, 5883, 5884, 5885, 5886, 5887, 5888, 5889, 5890, 5891, 5892, 5893, 5894, 5895, 10329, 10511, 14465, 14469, 14814, 14819, 15283, 15295, 15304, 15308, 15650, 15663, 19011, 20540, 20929, 20988, 21062, 21111, 21117, 21558, 21562, 21567, 22995, 23011, 23031, 23058, 23227, 23228, 23253, 23264, 23267, 23269, 23283, 23286, 23289, 23947, 24113, 24116, 25346, 26190, 27577, 29437, 29438, 29439, 29440, 29441, 29442, 29499, 33733, 33740, 33753, 40837, 40838, 44567, 61941, 61942, 61943, 62505, 62506, 62507, 62508, 62509, 62510, 62511, 62512, 62513, 62514, 62515, 62516, 62517, 62518, 62519, 62520, 62521, 62522, 62523, 62524, 62525, 62526, 62527, 71412, 71604, 71658, 71659, 71660, 71661, 87347, 87348, 87349, 87350, 87351, 87352, 87355, 87356, 87357, 87358, 87359, 87360, 87361, 87364, 87366, 87368, 87377, 100799, 118380, 118381, 118382, 118383, 118384, 118385, 131360, 151770, 151771};
		result = find_all_street_intersections("Danforth Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 1155, 1241, 1256, 1545, 1976, 2470, 2522, 3075, 3091, 3161, 3167, 3191, 3318, 3327, 5445, 5600, 5729, 5755, 6951, 6952, 6967, 6972, 6989, 7989, 8011, 8997, 9007, 9016, 9075, 11112, 11140, 12963, 15192, 15557, 16266, 16269, 16325, 16331, 16332, 16337, 16363, 16899, 17172, 17384, 19107, 19108, 19109, 20518, 20534, 23834, 27903, 27950, 27951, 38665, 39580, 39582, 40287, 40291, 42999, 43174, 44971, 44974, 46936, 46941, 46955, 46964, 46983, 46984, 47041, 47042, 47520, 47779, 48193, 48211, 48357, 48358, 48359, 48362, 48363, 48364, 48365, 50830, 50831, 52001, 52045, 62122, 62123, 62222, 62223, 63371, 70654, 96013, 96014, 96019, 96020, 96021, 96022, 96023, 96038, 96048, 96049, 96050, 96055, 96056, 96061, 96062, 96063, 96064, 96084, 96094, 96100, 96122, 96157, 96171, 96940, 100146, 102938, 103718, 104175, 104322, 104328, 104329, 107534, 115074, 115075, 115084, 115550, 115698, 115700, 115701, 115702, 115703, 115704, 115705, 116224, 116225, 116226, 116227, 133401, 133402, 134469, 136943, 136946, 136954, 146907, 151786, 151788, 151789, 151790, 151803, 151820, 156311, 156456, 156551, 156552, 156553, 156554, 162802, 162803, 162804, 162805};
		result = find_all_street_intersections("Queen Street West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {488, 978, 2320, 2522, 2523, 2524, 2525, 3012, 3874, 4022, 5491, 5492, 5498, 5542, 5901, 5905, 5922, 5947, 5961, 5993, 6013, 6014, 6036, 6047, 6061, 6099, 6105, 6106, 7588, 9689, 9698, 10541, 10542, 10543, 10633, 10634, 10635, 14387, 14400, 14991, 15019, 15029, 15030, 15039, 15046, 15079, 15082, 15086, 15102, 15110, 15118, 15121, 15376, 15673, 15679, 15692, 15700, 15711, 15712, 15717, 15718, 15724, 15734, 16506, 16759, 17404, 17409, 17421, 17425, 17444, 17451, 18557, 18576, 18750, 18757, 18758, 18761, 18774, 20789, 23143, 23144, 23145, 23146, 23147, 23148, 23149, 23150, 24417, 24428, 24429, 24448, 24449, 24452, 27958, 33762, 36253, 36254, 36261, 36904, 36910, 36972, 37128, 37129, 37130, 37131, 37132, 37133, 38749, 38771, 38772, 38773, 38774, 38775, 38776, 38777, 38778, 38779, 38780, 38781, 39390, 39391, 39400, 39432, 39433, 39553, 40435, 42117, 42119, 42120, 42121, 42122, 42123, 42124, 42125, 42126, 42127, 42128, 42129, 46999, 47226, 47238, 47520, 48195, 48196, 48805, 50832, 50833, 50834, 50835, 50836, 50837, 50838, 50839, 52504, 52510, 52515, 52530, 52543, 60433, 60434, 61982, 61983, 61984, 61985, 61986, 61987, 61988, 61989, 61990, 61991, 61992, 61993, 61994, 61995, 61996, 61997, 61998, 61999, 62000, 62001, 62002, 62003, 62007, 70644, 70800, 98338, 99254, 99334, 99429, 99519, 99544, 99547, 99548, 99549, 99550, 99551, 99552, 99553, 99554, 99555, 99556, 99557, 99558, 99559, 99560, 99561, 99562, 99563, 99564, 99565, 99566, 101750, 101752, 101755, 101757, 103743, 103744, 103748, 103749, 106340, 106341, 106342, 107148, 107154, 107453, 107454, 107456, 107457, 107460, 107461, 107462, 113116, 113117, 113118, 113119, 113120, 113121, 113136, 119141, 119142, 121100, 121101, 121102, 124646, 127946, 128345, 155271, 155272, 155838, 158726, 158727, 159531, 164247, 164248, 164249, 164250};
		result = find_all_street_intersections("Queen Street East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {32, 33, 34, 35, 482, 483, 484, 666, 1808, 5664, 5668, 5672, 5687, 5707, 5918, 7823, 7830, 7836, 7841, 8569, 9370, 9383, 9386, 9397, 9405, 9426, 9785, 9790, 11163, 11262, 11290, 11296, 11303, 11418, 12484, 12491, 12497, 12498, 13478, 17024, 17025, 17026, 17027, 17028, 17029, 20549, 20550, 22360, 22374, 22412, 22429, 22438, 28811, 28824, 31628, 31630, 31634, 38114, 64869, 67326, 69631, 69867, 70864, 70865, 70866, 70867, 70868, 70869, 70870, 70871, 96423, 96424, 96425, 96426, 96428, 96429, 96430, 96433, 96436, 98347, 99690, 99692, 99693, 99694, 100047, 100048, 100056, 100057, 100058, 100059, 100060, 100413, 100428, 100431, 100620, 100624, 100625, 100626, 100627, 100628, 100629, 100630, 100631, 100632, 100633, 100663, 100664, 100701, 100702, 100703, 100707, 100710, 100711, 100986, 101520, 101538, 101539, 101540, 101541, 101542, 101544, 101950, 101962, 101963, 101964, 101965, 101966, 101967, 101968, 101969, 101970, 101971, 101972, 101973, 101974, 101975, 101976, 104201, 113694, 113698, 113704, 113705, 115016, 115243, 115244, 115245, 115246, 115247, 115248, 117828, 120906, 120909, 120910, 120911, 120912, 120913, 120916, 120918, 120920, 120921, 120922, 120923, 120924, 124536, 124537, 124538, 124539, 124930, 128866, 128867, 128868, 128955, 128956, 128957, 130357, 131625, 131626, 131627, 131628, 131629, 131630, 131631, 145678, 145679, 145680, 145681, 145682, 145683, 148772, 157414, 158297, 158298, 158483, 158484, 158577, 158578, 161889, 161892, 161895, 161898, 161900};
		result = find_all_street_intersections("Avenue Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {534, 553, 554, 555, 556, 648, 649, 650, 651, 652, 653, 654, 655, 703, 704, 705, 706, 707, 708, 709, 1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1257, 1927, 1943, 2007, 2406, 2582, 2628, 2642, 2960, 3154, 3206, 4313, 4318, 4353, 4367, 6270, 6291, 6298, 6370, 6376, 6382, 6791, 6795, 6796, 6802, 6808, 6818, 6819, 6829, 6951, 7631, 7700, 7703, 7920, 7923, 8012, 8015, 8446, 8734, 9094, 9174, 9175, 9300, 9349, 9453, 9782, 10642, 11174, 11223, 13731, 13765, 13767, 13790, 14342, 17195, 17226, 17971, 17972, 17973, 18224, 18231, 18239, 18243, 18298, 18305, 18785, 18790, 18792, 18804, 18805, 18806, 18808, 18810, 18827, 18829, 19700, 20286, 20287, 20288, 20289, 20290, 20291, 20292, 20293, 20294, 20502, 21751, 22218, 22243, 22252, 22257, 22289, 22312, 22313, 22319, 22327, 22355, 22375, 22416, 22504, 22510, 22526, 22532, 22595, 22605, 22608, 22673, 22679, 23628, 28168, 28405, 28584, 28617, 28744, 28745, 28746, 28748, 28753, 28754, 28755, 28759, 28761, 28763, 28764, 28765, 28766, 28795, 28799, 28818, 28821, 28823, 28847, 29267, 29691, 29699, 29775, 31216, 31353, 31354, 32654, 32720, 32740, 34951, 34953, 34954, 35497, 36690, 37163, 38081, 38397, 40174, 40296, 40305, 40306, 42450, 43169, 43170, 43171, 43172, 49607, 49608, 49904, 49906, 49907, 49908, 49909, 49911, 49914, 49915, 49916, 49917, 49918, 57492, 57493, 57494, 57495, 57496, 57497, 57498, 62047, 62048, 62053, 62054, 62055, 62056, 62057, 62058, 62059, 62060, 62945, 62946, 62947, 62948, 65099, 65230, 67220, 67268, 67336, 67395, 67618, 67955, 68385, 68458, 68620, 69023, 69372, 70223, 70283, 79338, 79339, 79340, 79341, 79342, 79344, 79345, 79351, 79352, 79353, 79354, 79355, 79356, 79357, 84359, 84360, 84361, 84364, 84365, 84366, 84367, 84368, 84369, 84370, 84371, 84374, 84375, 84378, 84379, 84380, 84381, 84382, 84391, 84392, 84393, 84394, 84395, 84396, 84397, 84400, 84401, 84402, 84405, 84406, 84408, 84409, 84410, 84411, 84413, 84416, 84417, 84418, 84419, 84420, 84424, 84425, 84428, 84430, 84431, 84432, 85376, 85379, 85694, 85893, 85894, 85895, 85896, 85898, 85899, 95136, 95137, 95138, 95139, 95140, 95141, 95149, 95178, 95179, 95180, 95183, 95185, 95186, 95191, 95192, 95193, 95194, 95195, 95238, 95239, 95240, 95241, 95242, 95243, 95244, 95246, 95247, 95248, 98688, 98689, 98690, 98691, 98821, 99620, 99623, 99628, 99629, 99630, 99631, 100257, 100258, 100474, 100589, 100590, 100591, 100592, 100593, 100594, 100595, 102042, 102048, 102110, 102119, 102120, 102121, 102122, 102123, 102194, 102216, 102217, 102218, 102219, 102220, 102221, 102222, 102233, 102234, 102235, 102236, 102237, 102238, 102239, 102243, 102244, 102245, 102246, 107835, 107836, 107837, 107838, 107839, 107840, 107841, 107842, 107843, 107844, 108020, 108367, 108411, 108421, 111914, 111928, 111929, 111947, 111977, 113517, 114277, 119546, 119549, 119550, 119551, 119552, 119553, 119554, 119555, 119556, 119557, 119558, 120612, 120613, 120614, 126127, 126709, 126738, 126745, 126784, 128240, 128246, 128819, 128824, 128834, 128911, 128921, 128947, 128948, 128949, 128950, 128951, 128952, 128953, 128954, 131122, 131123, 131124, 131125, 131126, 132976, 132977, 132978, 132979, 132980, 132981, 132982, 132983, 132984, 133640, 133648, 133663, 133670, 133681, 133691, 133694, 134035, 134051, 134055, 134059, 134080, 138880, 138881, 138882, 143847, 143854, 143869, 143871, 143954, 144190, 144413, 144414, 144419, 144426, 144431, 144432, 147331, 147337, 147339, 147340, 147341, 147342, 147343, 149010, 149011, 149012, 149313, 150146, 151077, 151078, 151079, 151802, 154256, 154259, 158187, 159688, 160341, 160352, 160353, 160366, 160367, 160368, 161235, 161236, 161358, 161359, 162674, 162688, 162689, 162690, 164185, 164186, 164187, 164188, 164189, 164190, 164191, 164204};
		result = find_all_street_intersections("Bathurst Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {682, 683, 684, 685, 686, 687, 688, 689, 699, 700, 701, 702, 951, 1128, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1176, 1177, 1504, 2090, 2094, 2526, 2536, 2537, 2556, 2598, 2617, 2671, 2708, 2717, 2746, 2808, 3108, 3109, 3110, 3111, 3112, 3113, 3114, 3115, 3116, 3117, 3118, 3275, 3331, 3332, 3338, 4981, 4982, 5743, 5744, 6632, 6633, 6637, 6638, 6643, 6647, 6662, 6668, 6669, 6670, 6674, 6675, 6686, 6729, 7524, 7525, 7526, 7926, 9301, 9629, 9749, 9750, 9751, 9752, 9753, 9754, 9755, 9756, 9757, 9758, 9759, 9762, 9764, 9766, 9770, 9771, 9772, 9773, 9837, 10239, 10509, 10549, 10552, 10781, 11444, 11525, 11540, 11547, 11555, 11563, 13611, 13620, 13642, 13643, 13647, 13667, 13687, 13688, 13689, 13690, 13691, 13692, 13693, 13694, 13695, 13696, 13697, 13698, 13699, 13700, 13701, 13702, 13703, 13704, 13705, 13706, 13707, 13708, 13709, 13710, 13711, 13712, 13713, 13714, 13747, 15427, 15450, 15470, 15561, 15565, 15566, 15588, 15749, 15750, 16225, 16698, 16699, 17171, 17289, 17298, 17299, 17717, 17720, 17747, 17800, 17804, 17813, 17816, 17829, 17832, 18607, 18608, 18618, 18639, 18656, 18683, 20359, 20360, 20361, 22815, 23641, 26406, 26417, 26450, 26454, 26459, 26460, 28086, 28091, 28113, 28194, 28215, 28218, 28221, 29787, 29788, 32763, 32764, 33429, 33430, 33442, 33443, 34939, 34940, 34941, 34942, 34943, 34944, 34945, 34946, 34947, 34949, 35086, 35087, 35392, 35478, 35479, 35481, 36248, 36404, 40012, 40014, 50846, 50872, 50874, 50875, 50876, 50877, 50878, 50879, 50880, 50881, 59815, 65353, 68398, 69929, 70321, 70899, 70901, 83005, 83006, 83007, 83008, 83009, 83013, 84482, 84504, 84513, 85359, 95062, 95063, 95065, 95066, 95068, 95069, 95070, 95071, 98647, 98681, 98682, 98683, 98685, 98686, 99088, 99089, 99099, 99100, 99101, 99102, 99103, 99104, 99161, 100158, 100159, 100160, 100161, 100162, 102482, 102486, 102487, 108026, 108027, 119464, 119820, 119821, 119822, 120307, 120354, 120396, 120954, 124297, 124645, 129698, 129709, 129742, 129743, 129744, 129745, 129746, 129747, 129748, 131172, 131173, 131174, 134638, 134639, 139210, 139214, 139217, 139218, 139236, 139237, 139282, 139283, 139284, 139285, 139286, 139287, 139288, 139289, 139290, 139969, 141141, 142157, 143906, 144227, 146430, 146431, 149165, 151035, 151036, 151043, 151044, 151045, 151046, 151047, 151048, 151744, 151748, 151749, 151750, 151751, 151752, 151753, 151754, 158847, 158848, 158849, 158850, 161226, 161227, 165841};
		result = find_all_street_intersections("Dufferin Street");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {1578, 2890, 5295, 10028, 10651, 10685, 10749, 10985, 10995, 10997, 23779, 23782, 23784, 23786, 23788, 23842, 23843, 23844, 23845, 23846, 25887, 25891, 25893, 25895, 25897, 25898, 25899, 25900, 25901, 25902, 25903, 25904, 25906, 26234, 26239, 26247, 26250, 26298, 26301, 26304, 26305, 26307, 26308, 28639, 30179, 40218, 41538, 41542, 41546, 41602, 41603, 41767, 42296, 42297, 42298, 42299, 42331, 42559, 42560, 42561, 42562, 42563, 42567, 42568, 42570, 49967, 49968, 57448, 59157, 59220, 59356, 59450, 59912, 59913, 59940, 60071, 60230, 60482, 60497, 60498, 60575, 72519, 72569, 72572, 72583, 72593, 72599, 72607, 72628, 72700, 72703, 72709, 72722, 72774, 80468, 80469, 80470, 80501, 80534, 80554, 80555, 80556, 80582, 80586, 80588, 80590, 80591, 80592, 80593, 80594, 80595, 80596, 80597, 80598, 80599, 80600, 80776, 80784, 80788, 80789, 80827, 80889, 80891, 80892, 80894, 80897, 80924, 80925, 80928, 80933, 81132, 81146, 81176, 81177, 81184, 81211, 81212, 83614, 83619, 83627, 83629, 83638, 83642, 83648, 83651, 83655, 83656, 83660, 83662, 83666, 83715, 83716, 83721, 83731, 83751, 83759, 83762, 83764, 83767, 83770, 83829, 84026, 84037, 84044, 84068, 84069, 84071, 84077, 84083, 84085, 84139, 84141, 101101, 101108, 101579, 101592, 101593, 101704, 101705, 109480, 109481, 109488, 109519, 109539, 109697, 109699, 109711, 109726, 109727, 109728, 109731, 109732, 109734, 109735, 109736, 109737, 109738, 109739, 109748, 111123, 111193, 111206, 111217, 111222, 111223, 111224, 111225, 111226, 111227, 111228, 111232, 111234, 111235, 111236, 111237, 111238, 111239, 111242, 111243, 111244, 111245, 112403, 112409, 112418, 112419, 112420, 112421, 112422, 112423, 112424, 112425, 112426, 112427, 112428, 112429, 112430, 112431, 112432, 112433, 112434, 112435, 112436, 112437, 112438, 112439, 112440, 112441, 112442, 112443, 112444, 112445, 112446, 112447, 112448, 112449, 112450, 116737, 116738, 116757, 118356, 118357, 127988, 127989, 127991, 127992, 127993, 136072, 136073, 136074, 136075, 136076, 136077, 136078, 136079, 136080, 147545, 147552, 153943, 162832, 163624, 163635};
		result = find_all_street_intersections("Weston Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {200, 201, 202, 203, 204, 205, 5101, 8779, 8780, 8781, 8782, 8783, 8784, 13837, 14503, 14506, 14515, 14585, 14629, 15961, 15982, 15985, 18849, 20183, 20204, 20677, 20748, 21478, 21479, 21480, 21481, 21482, 21483, 21484, 21485, 21486, 21487, 21488, 21489, 21490, 21491, 21492, 21493, 21494, 23455, 24507, 24523, 24524, 24537, 24538, 24566, 24572, 24573, 24672, 24792, 24793, 26072, 26073, 26078, 26087, 26098, 26099, 26100, 26101, 26369, 26509, 26528, 26529, 26530, 29243, 31162, 31588, 31591, 31774, 31780, 31784, 31798, 32454, 32639, 32640, 39808, 40880, 41032, 41035, 41156, 41157, 41158, 41159, 41160, 41161, 41286, 41287, 41392, 41393, 41395, 41448, 41451, 41452, 41453, 41454, 41455, 53961, 53968, 53969, 53979, 53980, 53981, 53982, 53983, 53984, 53985, 58001, 58002, 58003, 58004, 58005, 58006, 58007, 58008, 58009, 58010, 58011, 58012, 58013, 58014, 68899, 73151, 73162, 73166, 73189, 73190, 73191, 73192, 73193, 73196, 73197, 73200, 73201, 73202, 73206, 73207, 73208, 73209, 73210, 73211, 73212, 73213, 73214, 73215, 73856, 73876, 73884, 73885, 73951, 73978, 73999, 74417, 74478, 74578, 74597, 74633, 74635, 74637, 74638, 74639, 74640, 74641, 74642, 74643, 74644, 74645, 74649, 74650, 74651, 74652, 74653, 74654, 74655, 74656, 74657, 74658, 74660, 74667, 77195, 77206, 77210, 77218, 77240, 77261, 77274, 77314, 77329, 77330, 77331, 77332, 77335, 77336, 77337, 77339, 77340, 77341, 77342, 77346, 77347, 78044, 78045, 78046, 78047, 78048, 78049, 78050, 78051, 78052, 78053, 78054, 78055, 78056, 78059, 78060, 78062, 78063, 78064, 78065, 78066, 78067, 78078, 78154, 78162, 78309, 78335, 78398, 78400, 78414, 78482, 78483, 78486, 78490, 78492, 78493, 78494, 78495, 78496, 78497, 78498, 78499, 78979, 78980, 78981, 78982, 78983, 78984, 78986, 79018, 79019, 79020, 79021, 79022, 79023, 79027, 79028, 79029, 79031, 79032, 79033, 79034, 79035, 85654, 85686, 86011, 86013, 86035, 86036, 86037, 86648, 86649, 86705, 86706, 86707, 86715, 86716, 86717, 86718, 86719, 99743, 99744, 100133, 100134, 100135, 100220, 100221, 100222, 100223, 100224, 100225, 101135, 101146, 101147, 101264, 101265, 101266, 101267, 102321, 102322, 102323, 115293, 115294, 115297, 115300, 115302, 115303, 115305, 115318, 115319, 115320, 115324, 115325, 115326, 115329, 115330, 115331, 115332, 115333, 115334, 115335, 115336, 115337, 115338, 115339, 115340, 115343, 115344, 115345, 115346, 115350, 115351, 115352, 115353, 115354, 115355, 115356, 115357, 115358, 121314, 121315, 121316, 124649, 124650, 125281, 125282, 125566, 125567, 125568, 125569, 125570, 126529, 129325, 129466, 129475, 129477, 129480, 129489, 129636, 130146, 130153, 130154, 130156, 130159, 130160, 130161, 130162, 130164, 130165, 130166, 130167, 130168, 130169, 130170, 130171, 130172, 130173, 130174, 131717, 131718, 131719, 131720, 133390, 133391, 134989, 135350, 147597, 147598, 147599, 147600, 147601, 147602, 147603, 149021, 149022, 149023, 149024, 149025, 151118, 152244, 152481, 155588, 155695, 155696, 159734, 163761, 163762, 163763, 163902};
		result = find_all_street_intersections("Sheppard Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {985, 986, 1718, 1719, 1720, 1721, 1722, 4668, 4843, 5741, 5742, 6720, 6721, 6736, 6737, 7126, 7129, 7132, 7135, 7136, 7142, 7145, 7157, 7160, 7473, 7474, 8674, 8675, 8679, 8743, 8759, 8983, 8985, 11594, 15390, 15391, 15400, 15404, 15405, 18201, 18213, 18220, 19487, 19490, 23646, 25507, 30222, 30223, 30356, 30357, 30358, 30359, 30365, 40219, 40220, 41722, 41731, 41745, 41749, 41750, 41751, 41752, 41753, 41816, 41817, 41818, 41819, 41820, 41821, 41822, 42106, 42390, 42391, 42392, 42393, 42394, 42395, 42396, 42397, 42398, 42581, 44055, 44074, 44075, 45153, 59288, 62917, 62927, 62930, 62931, 62932, 62933, 62934, 63583, 63584, 65690, 70400, 70401, 74047, 74060, 74061, 74062, 74063, 74064, 74065, 74066, 74067, 74068, 74069, 74070, 74071, 74072, 74958, 74959, 74960, 74961, 79904, 79905, 79906, 79933, 79934, 79941, 79942, 79947, 79948, 79949, 79967, 79983, 79986, 79988, 79989, 80003, 80004, 80010, 80011, 80012, 80025, 80038, 80053, 80065, 80072, 80077, 80089, 80090, 80092, 80120, 80126, 80219, 80266, 80270, 80290, 80294, 80303, 80481, 80483, 80527, 80532, 80569, 80572, 80578, 80603, 80604, 80605, 80606, 80607, 80608, 80610, 80611, 80612, 80613, 80614, 80615, 80616, 80617, 80619, 80620, 80621, 80622, 80623, 80624, 80625, 80626, 80627, 80628, 80629, 80630, 80631, 80632, 80633, 80634, 80635, 80636, 80637, 80638, 80639, 80640, 80641, 80642, 80708, 80709, 80776, 80777, 80873, 80876, 80877, 80878, 80879, 81146, 81198, 81211, 81212, 81213, 81220, 81222, 81223, 81224, 81325, 81335, 81336, 81364, 81390, 81432, 81438, 81439, 81440, 81445, 81477, 81478, 81479, 81490, 81592, 81703, 84358, 84360, 84361, 84362, 84363, 84364, 84372, 84373, 84375, 84376, 84377, 84383, 84384, 84385, 84386, 84387, 84388, 84389, 84390, 84433, 84434, 95055, 95062, 95063, 95064, 95065, 95066, 95067, 115427, 118594, 118595, 124334, 124338, 131133, 131243, 131642, 131643, 131737, 131738, 131739, 133176, 141833, 142966, 145132, 145133, 145134, 145135, 145136, 145137, 145138, 145139, 157300, 157688, 160358, 164198};
		result = find_all_street_intersections("Finch Avenue West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {859, 860, 861, 1718, 1729, 2210, 2211, 2212, 2213, 2214, 2215, 2933, 2935, 2938, 2942, 2943, 3759, 3760, 5824, 11839, 11862, 11875, 14140, 14141, 14142, 14143, 14470, 14472, 14689, 14755, 14757, 19907, 19908, 20696, 20700, 25798, 25810, 26183, 27555, 27556, 27557, 27558, 27559, 27560, 27561, 27562, 27563, 27564, 27565, 27566, 27567, 27568, 27569, 27570, 27571, 27572, 27573, 27574, 27575, 27576, 29383, 31757, 31761, 32393, 34552, 34553, 37000, 37001, 37002, 37004, 37008, 37010, 37011, 37012, 37014, 37015, 37016, 37017, 37018, 37019, 37020, 37021, 37022, 38155, 41104, 41325, 41337, 41344, 41436, 41437, 41438, 41439, 41440, 41441, 41442, 41459, 41461, 42470, 42472, 42473, 45150, 45152, 47490, 47491, 47494, 47495, 51766, 62144, 63557, 65716, 65717, 65718, 65737, 65738, 65836, 66880, 68123, 68780, 69998, 70386, 70394, 70395, 70396, 73569, 73577, 73606, 73662, 74739, 74794, 74965, 74973, 74974, 74975, 74976, 74979, 74982, 74983, 74984, 74987, 74988, 74989, 74990, 74991, 74992, 74993, 74994, 74995, 74996, 76150, 76240, 76260, 76263, 76264, 76265, 76266, 76267, 76343, 76344, 76345, 76346, 76351, 76353, 76355, 76358, 76359, 76360, 76394, 76395, 76403, 76404, 76405, 76406, 76407, 76408, 76409, 76410, 76411, 76412, 76413, 76415, 76416, 76417, 76418, 76419, 76420, 76421, 76422, 76423, 76424, 76425, 76426, 76624, 76625, 76628, 76629, 76630, 76631, 76632, 76633, 76634, 76635, 76636, 76637, 76638, 76639, 76640, 76641, 76642, 76643, 76646, 76647, 76650, 76651, 76652, 76653, 76654, 76655, 76656, 76657, 76658, 76659, 76660, 76661, 76662, 76683, 76684, 76685, 76686, 76687, 76688, 79697, 79698, 82219, 82223, 82247, 82249, 82250, 82251, 82252, 82253, 82254, 82255, 82256, 82257, 82258, 82259, 82260, 82261, 82262, 82263, 82264, 82265, 82266, 84341, 84342, 84343, 84349, 86378, 86379, 87640, 87646, 89509, 89569, 89972, 89973, 89974, 89975, 89976, 89977, 89978, 89979, 89980, 89983, 89984, 89985, 89986, 89987, 89988, 89989, 89990, 89991, 98671, 98672, 98673, 98674, 98675, 100105, 100106, 100107, 100108, 100109, 100110, 100111, 100112, 100299, 100300, 100301, 100302, 100303, 100304, 100305, 100306, 100307, 100308, 100309, 100310, 102168, 102169, 102170, 102171, 106573, 106574, 106576, 106577, 106578, 106580, 106581, 106583, 106584, 106585, 106586, 106587, 106588, 106609, 106610, 113273, 114095, 115613, 118590, 118591, 118592, 120902, 121245, 121246, 128480, 128482, 128529, 128531, 128532, 128533, 128534, 128535, 128536, 128537, 128538, 128539, 128540, 128541, 128542, 128543, 128544, 128545, 128546, 128547, 128548, 128550, 128551, 128552, 128553, 128554, 128555, 128556, 128558, 128559, 128561, 128562, 128563, 128564, 128565, 128566, 128567, 128568, 129990, 134561, 134563, 134564, 134565, 134566, 134567, 134568, 134569, 134570, 134571, 134572, 135894, 135895, 137170, 138606, 138607, 138608, 138609, 138610, 138611, 138616, 138617, 138618, 138619, 138620, 138621, 138622, 138623, 138624, 138632, 139123, 139204, 139205, 146749, 149568, 149569, 150236, 150237, 150238, 150239, 150240, 150942, 150943, 150944, 150945, 150980, 151057, 151058, 151059, 151060, 151061, 151062, 151065, 151066, 151069, 151070, 151071, 151073, 151139, 151140, 152185, 152382, 152384, 152385, 152386, 152387, 152388, 152389, 152951, 155517, 155518, 155519, 156173, 156174, 160014, 160015, 160016, 160017, 160051, 161070};
		result = find_all_street_intersections("Steeles Avenue East");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {699, 700, 2755, 2756, 2757, 2758, 2763, 2764, 2775, 2779, 2792, 2803, 2812, 2813, 6728, 9745, 9746, 9747, 9748, 20555, 20556, 20557, 22279, 22280, 22543, 22544, 22548, 22549, 22550, 22551, 22552, 22555, 22556, 22557, 22558, 22560, 22561, 22562, 22588, 22589, 22590, 42555, 42556, 42557, 42558, 95072, 95073, 95074, 102865, 102866, 102867, 104278, 104279, 124926, 124927, 128266, 128267, 130175, 130176};
		result = find_all_street_intersections("William R. Allen Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 538, 539, 540, 541, 542, 543, 544, 545, 546, 553, 563, 565, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 1178, 1270, 1271, 8033, 8991, 9569, 10577, 10957, 10958, 10959, 10960, 10961, 10962, 14065, 14066, 15482, 15486, 15488, 15491, 16043, 16197, 16210, 16211, 16648, 16649, 16650, 16651, 16652, 16654, 16656, 16657, 16680, 17840, 17845, 17846, 17848, 17860, 17871, 17878, 17893, 17894, 17941, 17945, 17949, 17957, 17960, 17965, 17969, 17970, 20276, 20277, 20296, 20303, 20309, 20325, 20339, 20351, 20535, 23491, 25583, 25596, 25604, 25608, 26044, 26047, 26064, 27603, 27611, 27619, 27625, 27626, 27627, 30381, 30392, 30398, 30410, 30415, 30424, 30428, 30430, 30432, 30436, 30440, 30444, 30459, 30471, 30476, 30484, 30488, 30504, 30512, 30515, 30531, 30534, 30539, 30555, 30557, 30565, 30573, 30577, 30579, 30581, 30584, 30588, 30611, 30615, 30625, 30626, 30627, 30641, 30643, 30651, 30658, 30660, 39955, 39956, 39957, 41089, 41090, 41091, 41092, 45367, 45368, 46814, 46815, 46816, 46817, 46818, 49618, 50905, 54260, 54262, 60931, 62561, 62942, 62943, 63117, 63119, 70474, 70475, 70511, 72470, 84982, 84983, 89429, 98775, 98776, 98777, 98778, 98779, 98780, 98784, 98871, 98872, 98873, 99606, 101833, 101834, 101835, 102794, 102823, 114158, 114159, 114258, 114259, 114260, 115444, 116713, 116714, 119398, 119811, 119812, 119823, 119824, 120802, 120803, 120804, 124966, 127574, 128145, 128729, 130994, 133208, 133209, 133210, 133211, 133212, 133412, 133413, 133414, 136879, 136880, 136881, 136882, 136883, 144264, 144265, 144293, 144344, 144512, 144516, 145184, 145844, 145845, 148906, 148953, 148954, 148955, 149060, 150509, 150510, 150511, 150512, 150513, 150514, 150515, 150728, 150729, 150730, 150731, 150732, 150898, 151253, 151256, 151257, 151258, 151259, 151260, 151261, 151264, 151268, 151269, 151274, 151275, 151276, 151277, 151278, 151279, 151280, 151281, 151294, 151295, 151296, 151297, 151303, 151325, 151326, 151327, 151328, 151329, 151330, 151338, 151339, 151340, 151341, 151347, 151348, 159341, 159342, 159343, 159344, 159345, 159346, 159347, 159348, 159349, 161243, 162075, 162077, 162079, 162080, 162083, 162084, 162088, 162089, 162093, 162094, 162095, 162099, 162516, 162517, 162518, 162519, 162520, 162791, 162792, 162793, 162957, 162959, 162962, 162974, 162975, 162976, 162977, 162978, 162979, 162980, 162981, 162982, 162983, 162984, 162985, 162986, 162987, 162988, 162989, 162990, 162991, 162992, 164311, 164312};
		result = find_all_street_intersections("Lake Shore Boulevard West");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {10965, 10969, 10971, 14219, 18276, 25638, 25639, 27708, 33696, 35192, 35193, 35194, 35195, 35202, 35203, 35204, 43151, 43378, 44121, 44650, 44663, 44839, 44941, 44942, 45046, 45047, 45068, 45084, 45085, 45469, 45505, 46446, 46462, 46463, 47838, 47952, 47956, 51217, 51221, 51236, 51238, 51247, 51268, 60902, 60903, 60904, 60905, 60906, 60907, 60908, 60909, 60910, 60911, 60912, 60913, 60914, 60915, 90481, 90783, 90833, 90894, 90923, 91287, 91531, 91557, 91560, 92792, 92793, 92798, 92828, 92840, 92841, 94006, 97324, 97328, 97332, 97333, 97335, 97337, 97339, 97344, 97345, 112458, 114786, 114787, 114788, 114790, 114791, 114794, 114796, 114797, 114798, 114799, 114800, 114806, 114811, 114813, 114817, 114818, 114819, 114822, 114824, 114825, 114832, 114834, 114835, 114836, 114837, 114840, 114841, 114849, 114850, 114853, 114855, 114856, 114857, 114858, 114859, 114860, 114861, 114862, 114868, 114873, 114874, 114875, 114876, 114878, 114879, 114880, 114882, 114883, 114889, 114890, 114897, 114899, 114900, 114905, 114912, 114913, 114914, 114918, 114919, 114924, 114925, 114926, 116025, 116027, 116029, 116362, 116363, 116382, 116383, 116384, 116385, 116401, 119809, 120176, 120177, 120178, 120184, 121250, 121251, 121252, 121253, 121254, 121255, 121256, 121257, 121720, 121721, 121723, 121731, 121743, 121744, 136858, 141201, 147848, 147854, 147855, 147857, 147858, 147859};
		result = find_all_street_intersections("Erin Mills Parkway");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {547, 3971, 4047, 4051, 4053, 4941, 5073, 6673, 13999, 14001, 14036, 14037, 14038, 14039, 14040, 14041, 14042, 14197, 14198, 14199, 20678, 20679, 20684, 21762, 23496, 23497, 23498, 23532, 23541, 27198, 27199, 27200, 27235, 27236, 27237, 28079, 28080, 28081, 29679, 29680, 41424, 45405, 70782, 72098, 74186, 74202, 74203, 74204, 74205, 74206, 74207, 74255, 74261, 74262, 74263, 74264, 74265, 74266, 74285, 74632, 74633, 74634, 74635, 74675, 74676, 74677, 74678, 74679, 74680, 74681, 75764, 75765, 75766, 75767, 75769, 75770, 75771, 75773, 77151, 77452, 77454, 77462, 77463, 77468, 77469, 77470, 77471, 77472, 77473, 77474, 77475, 77476, 77477, 77478, 77479, 79662, 79665, 79669, 79671, 79672, 79673, 79674, 79675, 79676, 79677, 79678, 79679, 79680, 79681, 79682, 79683, 79684, 79685, 79686, 79687, 79688, 79689, 84712, 98669, 98670, 98693, 98694, 98695, 98696, 98697, 98698, 98699, 99719, 101831, 101832, 101869, 101870, 101871, 101876, 122502, 129989, 155555, 155656, 155660, 155661, 155662, 155663, 155664, 155665};
		result = find_all_street_intersections("Morningside Avenue");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
		expected_result = {4216, 4217, 4225, 4226, 4230, 4235, 4236, 4275, 4276, 4277, 4278, 4279, 4280, 4281, 4282, 17053, 17054, 17055, 17056, 17057, 17058, 17059, 17060, 17061, 17062, 17063, 20580, 20599, 20658, 20659, 20660, 20661, 25663, 28148, 28732, 28733, 29762, 29763, 29764, 37661, 37682, 37688, 37691, 37693, 38189, 38190, 38191, 38192, 38193, 38194, 38195, 38196, 38197, 38198, 38199, 38200, 38201, 38202, 38203, 38204, 38688, 38728, 38729, 38730, 38731, 38739, 41317, 41318, 41319, 41514, 48920, 52564, 52565, 52566, 52567, 69750, 71731, 71744, 71747, 71766, 71781, 71789, 71796, 71804, 71812, 71915, 71916, 72106, 72107, 72108, 73252, 73294, 73465, 75049, 75102, 75119, 75141, 75198, 75227, 75310, 75311, 75312, 75323, 75324, 75325, 75326, 75356, 75357, 76193, 76203, 76215, 76216, 76248, 76249, 76251, 76254, 76269, 76270, 76280, 76286, 76312, 76315, 76328, 76329, 76330, 76331, 76332, 76333, 76334, 76335, 76336, 76337, 76338, 76339, 76340, 76341, 76342, 76343, 76344, 76347, 76348, 76349, 76350, 76351, 76352, 76353, 76354, 76356, 76357, 76364, 76365, 78404, 78973, 78974, 78975, 78976, 78977, 78978, 78979, 78981, 78982, 78984, 78985, 85412, 86164, 86182, 86183, 86184, 86185, 86186, 86187, 86188, 86189, 86190, 86191, 86903, 86975, 86993, 87084, 87085, 87086, 87087, 87089, 87090, 87091, 87092, 87266, 87270, 87271, 87273, 87286, 87288, 87289, 87290, 87291, 87292, 87294, 87295, 87296, 87297, 87298, 87299, 87300, 87301, 87302, 87303, 87304, 87305, 87306, 87307, 87308, 87309, 87310, 87311, 87312, 87522, 87528, 88842, 88995, 89129, 89130, 100169, 101435, 101436, 101437, 101438, 101439, 101440, 101441, 101442, 101443, 101446, 101447, 101448, 101451, 101455, 101456, 101457, 101502, 101503, 101504, 105442, 105443, 105444, 105445, 112492, 112509, 112510, 112536, 112792, 112962, 112963, 112986, 113008, 113504, 123155, 123156, 123160, 123161, 123162, 123163, 123164, 123165, 123166, 123167, 124438, 131389, 131390, 131391, 141033, 141034, 141035, 141036, 141037, 141038, 146017, 148857, 150119, 152230, 152735, 157403, 157404, 157405, 157406, 157407, 157408, 158132, 158915, 159376, 161801, 163785, 163786, 163795};
		result = find_all_street_intersections("McCowan Road");
		std::sort(result.begin(), result.end());
		CHECK_EQUAL(expected_result, result);
		
	}

	TEST_FIXTURE(Map_Fixture, distance_functionality) {
		float expected;
		float actual;
		
		expected = 0;
		actual = find_distance_between_two_points(LatLon(43.70674, -79.39832), LatLon(43.70674, -79.39832));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 5795.502445682106;
		actual = find_distance_between_two_points(LatLon(43.70674, -79.39832), LatLon(43.65572, -79.38369));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1004.891712468667;
		actual = find_distance_between_two_points(LatLon(43.64733, -79.37967), LatLon(43.65632, -79.38091));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1043.156730450085;
		actual = find_distance_between_two_points(LatLon(43.66139, -79.38307), LatLon(43.65243, -79.37924));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 245.2059793921245;
		actual = find_distance_between_two_points(LatLon(43.64992, -79.38075000000001), LatLon(43.64916, -79.37788999999999));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 223.8238412168463;
		actual = find_distance_between_two_points(LatLon(43.67026, -79.38678), LatLon(43.66972, -79.38946));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 4857.506545485718;
		actual = find_distance_between_two_points(LatLon(43.68814, -79.39412), LatLon(43.64528, -79.38253));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1006.653578635471;
		actual = find_distance_between_two_points(LatLon(43.65044, -79.37841), LatLon(43.65909, -79.38209000000001));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 2501.190986258448;
		actual = find_distance_between_two_points(LatLon(43.67103, -79.38312999999999), LatLon(43.64864, -79.38024));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1304.44114716316;
		actual = find_distance_between_two_points(LatLon(43.65481, -79.38848), LatLon(43.66408, -79.39841));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1287.545927657807;
		actual = find_distance_between_two_points(LatLon(43.66081, -79.38583), LatLon(43.64987, -79.39106));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 1469.49560721438;
		actual = find_distance_between_two_points(LatLon(43.66493, -79.38455), LatLon(43.65187, -79.38179));
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 2784.653422257717;
		actual = find_distance_between_two_points(LatLon(43.6687, -79.39413), LatLon(43.64398, -79.38865));
		CHECK(relative_error(expected, actual) < 0.05);
		
	}

	TEST_FIXTURE(Map_Fixture, segment_length_functionality) {
		float expected;
		float actual;
		
		expected = 28.37000932206896;
		actual = find_street_segment_length(76);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 32.58644993973689;
		actual = find_street_segment_length(659);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 38.38746406628566;
		actual = find_street_segment_length(1060);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 93.39203291341271;
		actual = find_street_segment_length(1417);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 11.82815810889016;
		actual = find_street_segment_length(783);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 13.94040980272965;
		actual = find_street_segment_length(397);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 64.94619230874328;
		actual = find_street_segment_length(361);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 41.73747089354383;
		actual = find_street_segment_length(359);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 10.69819173725275;
		actual = find_street_segment_length(712);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 6.811617386803849;
		actual = find_street_segment_length(2180);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 32.73202923289862;
		actual = find_street_segment_length(19);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 14.21901154657518;
		actual = find_street_segment_length(461);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 7.79131530840147;
		actual = find_street_segment_length(572);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 10.29720373311465;
		actual = find_street_segment_length(23072);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 29.61931593846006;
		actual = find_street_segment_length(158);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 74.76107821223673;
		actual = find_street_segment_length(800);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 333.5445886372028;
		actual = find_street_segment_length(693);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 136.3419886921855;
		actual = find_street_segment_length(2391);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 82.22153854247983;
		actual = find_street_segment_length(440);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 39.05230726094867;
		actual = find_street_segment_length(24810);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 37.40608376533224;
		actual = find_street_segment_length(13213);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 24.22494896391064;
		actual = find_street_segment_length(3669);
		CHECK(relative_error(expected, actual) < 0.05);
		
	}

	TEST_FIXTURE(Map_Fixture, street_length_functionality) {
		float expected;
		float actual;
		
		expected = 40193.73221828681;
		actual = find_street_length("Yonge Street");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 35175.29760341992;
		actual = find_street_length("Eglinton Avenue East");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 4335.945579387473;
		actual = find_street_length("Bay Street");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 31003.20294458751;
		actual = find_street_length("Dundas Street West");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 5116.039103393104;
		actual = find_street_length("College Street");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 3212.543516904523;
		actual = find_street_length("University Avenue");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 19060.85023958547;
		actual = find_street_length("Bloor Street West");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 10885.81628272117;
		actual = find_street_length("Danforth Avenue");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 11545.69616987917;
		actual = find_street_length("Queen Street West");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 14429.95418963504;
		actual = find_street_length("Queen Street East");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 10619.02780043339;
		actual = find_street_length("Avenue Road");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 36261.13542555516;
		actual = find_street_length("Bathurst Street");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 40036.39898647602;
		actual = find_street_length("Dufferin Street");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 35008.54471229232;
		actual = find_street_length("Weston Road");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 28319.65301328929;
		actual = find_street_length("Sheppard Avenue East");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 25872.81391299298;
		actual = find_street_length("Finch Avenue West");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 46733.03225770919;
		actual = find_street_length("Steeles Avenue East");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 13660.50099305937;
		actual = find_street_length("William R. Allen Road");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 23926.28816337195;
		actual = find_street_length("Lake Shore Boulevard West");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 23680.64178126276;
		actual = find_street_length("Erin Mills Parkway");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 14991.16402220647;
		actual = find_street_length("Morningside Avenue");
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 27614.30731837841;
		actual = find_street_length("McCowan Road");
		CHECK(relative_error(expected, actual) < 0.05);
		
	}

	TEST_FIXTURE(Map_Fixture, segment_travel_time_functionality) {
		float expected;
		float actual;
		
		expected = 0.03404401118648275;
		actual = find_segment_travel_time(76);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.03258644993973689;
		actual = find_segment_travel_time(659);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.05758119609942849;
		actual = find_segment_travel_time(1060);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.1400880493701191;
		actual = find_segment_travel_time(1417);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.01774223716333525;
		actual = find_segment_travel_time(783);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.01672849176327558;
		actual = find_segment_travel_time(397);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.09741928846311493;
		actual = find_segment_travel_time(361);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.05008496507225259;
		actual = find_segment_travel_time(359);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.0128378300847033;
		actual = find_segment_travel_time(712);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.01021742608020577;
		actual = find_segment_travel_time(2180);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.03927843507947834;
		actual = find_segment_travel_time(19);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.02132851731986277;
		actual = find_segment_travel_time(461);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.0116869729626022;
		actual = find_segment_travel_time(572);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.01544580559967198;
		actual = find_segment_travel_time(23072);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.02961931593846006;
		actual = find_segment_travel_time(158);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.1121416173183551;
		actual = find_segment_travel_time(800);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.5003168829558042;
		actual = find_segment_travel_time(693);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.1168645617361589;
		actual = find_segment_travel_time(2391);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.08222153854247984;
		actual = find_segment_travel_time(440);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.05857846089142301;
		actual = find_segment_travel_time(24810);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.03740608376533224;
		actual = find_segment_travel_time(13213);
		CHECK(relative_error(expected, actual) < 0.05);
		
		expected = 0.02422494896391064;
		actual = find_segment_travel_time(3669);
		CHECK(relative_error(expected, actual) < 0.05);
		
	}

	TEST_FIXTURE(Map_Fixture, closest_poi_functionality) {
		CHECK_EQUAL("CIBC", find_closest_point_of_interest(LatLon(43.70674, -79.39832)));
		CHECK_EQUAL("RBC Royal Bank", find_closest_point_of_interest(LatLon(43.65572, -79.38369)));
		CHECK_EQUAL("Bixi Bike Sharing", find_closest_point_of_interest(LatLon(43.64733, -79.37967)));
		CHECK_EQUAL("Dundas", find_closest_point_of_interest(LatLon(43.65632, -79.38091)));
		CHECK_EQUAL("College", find_closest_point_of_interest(LatLon(43.66139, -79.38307)));
		CHECK_EQUAL("Queen", find_closest_point_of_interest(LatLon(43.65243, -79.37924)));
		CHECK_EQUAL("Northern Ontario Building", find_closest_point_of_interest(LatLon(43.64992, -79.38075000000001)));
		CHECK_EQUAL("King", find_closest_point_of_interest(LatLon(43.64916, -79.37788999999999)));
		CHECK_EQUAL("The Grind", find_closest_point_of_interest(LatLon(43.67026, -79.38678)));
		CHECK_EQUAL("TD Canada Trust", find_closest_point_of_interest(LatLon(43.66972, -79.38946)));
		CHECK_EQUAL("INFOTOGO Map", find_closest_point_of_interest(LatLon(43.68814, -79.39412)));
		CHECK_EQUAL("Casey's", find_closest_point_of_interest(LatLon(43.64528, -79.38253)));
		CHECK_EQUAL("TD Canada Trust", find_closest_point_of_interest(LatLon(43.65044, -79.37841)));
		CHECK_EQUAL("Shakeolait", find_closest_point_of_interest(LatLon(43.65909, -79.38209000000001)));
		CHECK_EQUAL("Church St & Bloor St E", find_closest_point_of_interest(LatLon(43.67103, -79.38312999999999)));
		CHECK_EQUAL("BMO Bank of Montreal", find_closest_point_of_interest(LatLon(43.64864, -79.38024)));
		CHECK_EQUAL("St. Patrick", find_closest_point_of_interest(LatLon(43.65481, -79.38848)));
		CHECK_EQUAL("Joseph L. Rotman Library", find_closest_point_of_interest(LatLon(43.66408, -79.39841)));
		CHECK_EQUAL("Timothy's World Coffee", find_closest_point_of_interest(LatLon(43.66081, -79.38583)));
		CHECK_EQUAL("Starbucks Coffee", find_closest_point_of_interest(LatLon(43.64987, -79.39106)));
		CHECK_EQUAL("Not Just Noodles", find_closest_point_of_interest(LatLon(43.66493, -79.38455)));
		CHECK_EQUAL("Starbucks Coffee", find_closest_point_of_interest(LatLon(43.65187, -79.38179)));
		CHECK_EQUAL("Second Cup", find_closest_point_of_interest(LatLon(43.6687, -79.39413)));
		CHECK_EQUAL("CN Tower/Ripley's Aquarium Canada", find_closest_point_of_interest(LatLon(43.64398, -79.38865)));
		CHECK_EQUAL("La Prep", find_closest_point_of_interest(LatLon(43.64638, -79.38408)));
	}

        //Checking all getters in MyInterData Class
        TEST_FIXTURE(Map_Fixture,Intersection_Contructor_MyInterData){
            
            //Correct Data to check getters against
            unsigned testID =50;//"Mill Street & Yonge Street (1)";
            LatLon testLatlon(43.6624,-79.426); 
            string testStreet[4]= {"Wilcox St.","Charles Ave.", "Magenta St.", "Filimont Ave."};
            vector<unsigned> testStreetSegs= {29,30,115195,115196};
            vector<string> testStreetNames= {testStreet[0],testStreet[1],testStreet[2],testStreet[3]};
            vector<unsigned> testAdj={49,51,29664};
            
            MyInterData thisIntersectionName=MyInterData(testID, testLatlon, testStreetSegs, testStreetNames, testAdj);
            
            CHECK_EQUAL(43.6624,thisIntersectionName.getLatLon().lat);
            CHECK_EQUAL(-79.426,thisIntersectionName.getLatLon().lon);
            CHECK_EQUAL(50, thisIntersectionName.getID());
            
            CHECK(testStreetSegs==thisIntersectionName.getSSIDs());
            CHECK(testStreetNames==thisIntersectionName.getInterStreets());
            CHECK(testAdj==thisIntersectionName.getAdjInterIDs());
        }

}
