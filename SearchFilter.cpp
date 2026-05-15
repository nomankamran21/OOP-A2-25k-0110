#include "SearchFilter.h"


SearchFilter::SearchFilter()
    : brand(""), model(""), minPrice(0), maxPrice(1e9),
      minYear(1980), maxYear(2025), maxMileage(500000),
      transmission(""), defaultBrand(new string("Any")) {}


SearchFilter::SearchFilter(const string& br, double minP, double maxP,
                           int minY, int maxY, int maxMil)
    : brand(br), model(""), minPrice(minP), maxPrice(maxP),
      minYear(minY), maxYear(maxY), maxMileage(maxMil),
      transmission(""), defaultBrand(new string("Any")) {}


SearchFilter::~SearchFilter() {
    delete defaultBrand;
}
void SearchFilter::setBrand(const string& b)           { brand = b; }
void SearchFilter::setModel(const string& m)           { model = m; }
void SearchFilter::setPriceRange(double mn, double mx) { minPrice = mn; maxPrice = mx; }
void SearchFilter::setYearRange(int mn, int mx)        { minYear = mn; maxYear = mx; }
void SearchFilter::setMaxMileage(int m)                { maxMileage = m; }
void SearchFilter::setTransmission(const string& t)    { transmission = t; }


string SearchFilter::getBrand()      const { return brand; }
string SearchFilter::getModel()      const { return model; }
double SearchFilter::getMinPrice()   const { return minPrice; }
double SearchFilter::getMaxPrice()   const { return maxPrice; }
int    SearchFilter::getMinYear()    const { return minYear; }
int    SearchFilter::getMaxYear()    const { return maxYear; }
int    SearchFilter::getMaxMileage() const { return maxMileage; }


void SearchFilter::display() const {
    cout << "Filter: Brand=" << (brand.empty() ? *defaultBrand : brand)
         << " | Price=[" << minPrice << "–" << maxPrice << "]"
         << " | Year=["  << minYear  << "–" << maxYear  << "]"
         << " | MaxMileage=" << maxMileage << "\n";
}

bool SearchFilter::matches(const Listing& lst) const {
    return lst.matchesFilter(brand, minPrice, maxPrice, minYear, maxYear);
}

void SearchFilter::reset() {
    brand = ""; model = ""; minPrice = 0; maxPrice = 1e9;
    minYear = 1980; maxYear = 2025; maxMileage = 500000; transmission = "";
    cout << "[SearchFilter] Reset to defaults.\n";
}

bool SearchFilter::isDefault() const {
    return brand.empty() && minPrice == 0 && maxPrice >= 1e9;
}
