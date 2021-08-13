#include "DummyStatusProvider.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "utils/Util.h"

namespace mk_robotics
{
    std::string DummyStatusProvider::getStatus()
    {
        static std::array<std::string, 12> hg{"Wilk na mikrofonie w głowie się nie miesci",
                                              "Jebac leszczy z lamusami się nie piescic",
                                              "Nie ma czasu glupot nie chce pieprzyc",
                                              "Jesli ci się nie podoba wylacz jak masz gescik",
                                              "I tak wszystkich nie uda ci się skreslic",
                                              "Mam sic strescic sluchaj pierwszej czecci",
                                              "Hemp Gru prosto z ulicy wiesci",
                                              "Ja i moje ziomki nikt gorszy nikt lepszy",
                                              "Jestem po to by prawde przyniesc ci",
                                              "Policyjne scierwo to wrog najwiekszy",
                                              "Twarda bania i zacisniete piesci",
                                              "Uwalniam instynkt gdy atmosfera się zagesci"};

        boost::property_tree::ptree pt;
        pt.put("id", util::randomIntFromRange(0, 100));
        pt.put("content", hg[util::randomIntFromRange(0, hg.size() - 1)]);
        pt.put("type", "log");
        pt.put("timestamp", std::time(0));
        pt.put("priority", util::randomIntFromRange(0, 3));
        std::stringstream ss;
        boost::property_tree::json_parser::write_json(ss, pt);
        return ss.str();
    }
}