#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Định nghĩa struct để lưu trữ thông tin dân số
struct DanSo {
    int nam;
    int so_nguoi_sinh_ra;
};

// Hàm tìm năm có số người sinh ra nhiều nhất
DanSo nam_lon_nhat(const vector<DanSo> &ds) {
    return *max_element(ds.begin(), ds.end(), [](const DanSo& a, const DanSo& b) {
        return a.so_nguoi_sinh_ra < b.so_nguoi_sinh_ra;
    });
}

// Hàm tìm năm có số người sinh ra ít nhất
DanSo nam_be_nhat(const vector<DanSo> &ds) {
    return *min_element(ds.begin(), ds.end(), [](const DanSo& a, const DanSo& b) {
        return a.so_nguoi_sinh_ra < b.so_nguoi_sinh_ra;
    });
}

// Hàm in các năm có cùng số lượng người sinh ra
void nam_cung_nguoi_sinh_ra(const vector<DanSo> &ds) {
    map<int, vector<int>> dem_danso;

    for(const auto& dan_so : ds) {
        dem_danso[dan_so.so_nguoi_sinh_ra].push_back(dan_so.nam);
    }

    cout << "Cac nam co cung so luong nguoi sinh ra:\n";
    for(const auto& entry : dem_danso) {
        if(entry.second.size() > 1) {
            cout << "So luong nguoi: " << entry.first << " - Nam: ";
            for(int year : entry.second) {
                cout << year << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    // Dữ liệu dân số theo năm
    vector<DanSo> ds = {
        {1920, 19}, {1921, 77}, {1922, 40}, {1923, 90}, {1924, 2}, {1925, 25}, {1926, 54}, {1927, 17}, {1928, 79}, {1929, 6},
        {1930, 44}, {1931, 24}, {1932, 14}, {1933, 4}, {1934, 95}, {1935, 47}, {1936, 66}, {1937, 48}, {1938, 23}, {1939, 98}, 
        {1940, 15}, {1941, 86}, {1942, 25}, {1943, 50}, {1944, 9}, {1945, 29}, {1946, 64}, {1947, 3}, {1948, 67}, {1949, 4},
        {1950, 90}, {1951, 81}, {1952, 74}, {1953, 34}, {1954, 98}, {1955, 13}, {1956, 87}, {1957, 96}, {1958, 56}, {1959, 90},
        {1960, 49}, {1961, 85}, {1962, 94}, {1963, 66}, {1964, 19}, {1965, 95}, {1966, 47}, {1967, 42}, {1968, 65}, {1969, 87}, {1970, 11}
    };

    // Tìm và in năm có số người sinh ra nhiều nhất và ít nhất
    DanSo max_nam = nam_lon_nhat(ds);
    DanSo min_nam = nam_be_nhat(ds);

    cout << "Nam co so nguoi sinh ra nhieu nhat: " << max_nam.nam
         << " voi " << max_nam.so_nguoi_sinh_ra << " nguoi." << endl;
    cout << "Nam co so nguoi sinh ra it nhat: " << min_nam.nam
         << " voi " << min_nam.so_nguoi_sinh_ra << " nguoi." << endl;

    // In các năm có cùng số lượng người sinh ra
    nam_cung_nguoi_sinh_ra(ds);

    return 0;
}