#include "mainwindow.h"
#include <QApplication>

//#include "xlsxdocument.h"
//#include "xlsxchartsheet.h"
//#include "xlsxcellrange.h"
//#include "xlsxchart.h"
//#include "xlsxrichstring.h"
//#include "xlsxworkbook.h"
//using namespace QXlsx;

//#include <DataFrame/DataFrame.h>                   // Main DataFrame header
//#include <DataFrame/DataFrameFinancialVisitors.h>  // Financial algorithms
//#include <DataFrame/DataFrameMLVisitors.h>         // Machine-learning algorithms
//#include <DataFrame/DataFrameStatsVisitors.h>      // Statistical algorithms
//#include <DataFrame/Utils/DateTime.h>              // Cool and handy date-time object

//#include <iostream>
//using namespace hmdf;
//using StrDataFrame = StdDataFrame<std::string>;

//void test (){
//    StrDataFrame    ibm_df;
//    ibm_df.read("data/IBM.csv", io_format::csv2);
//    std::cout << "There are " << ibm_df.get_column<double>("IBM_Close").size()
//              << " IBM close prices" << std::endl;
//    std::cout << "There are " << ibm_df.get_index().size() << " IBM indices" << std::endl;
//}

//void xlsxTest(){

//    QXlsx::Document xlsx;
//    xlsx.write("A1","Hello QT");
//    xlsx.saveAs("test.csv");
//}


int main(int argc, char *argv[])
{
//    test();
    QApplication a(argc, argv);

//    xlsxTest();

    MainWindow w;
    w.show();
    return a.exec();
}
