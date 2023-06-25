#include "../include/Database.hpp"

int main() {
    Database db("airport_passengers");
    Row r1(
            "Ivanov",
            "A. A.",
            8,
            21,
            "Kazan",
            "12:15",
            false,
            "No children."
    );
    Row r2(
            "Zhuravlev",
            "I. S.",
            20,
            15,
            "Vladivostok",
            "19:24",
            true,
            ""
    );
    Row r3(
            "Volkova",
            "Z. I",
            41,
            32,
            "Krasnoyarsk",
            "15:06",
            false,
            "2 children: 14 y.o. and 17 y."
    );
    Row r4(
            "Belova",
            "T. M.",
            8,
            40,
            "Chita",
            "22:01",
            true,
            "No children."
    );
    Row r5(
            "Vinogradov",
            "S. S.",
            3,
            100,
            "Paris",
            "20:08",
            true,
            "No children."
    );
    Row r6(
            "Soloveva",
            "A. P.",
            8,
            5,
            "Volgograd",
            "17:17",
            false,
            "No children."
    );
    db.add_row(r1);
    db.add_row(r2);
    db.add_row(r3);
    db.add_row(r4);
    db.add_row(r5);
    db.add_row(r6);

    db.print();
    db.lab_task(8, 10);

    return 0;
}
