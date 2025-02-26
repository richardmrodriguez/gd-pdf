#include "gdexample.h"
#include <algorithm>
#include <cstring>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("testExportFunc"), &GDExample::testExportFunc);
}
void _pdfTest(pdfio_file_t* pdf) {
    UtilityFunctions::print("PDF File loaded!");
    
    size_t        i;                // Looping var
    size_t        count;            // Number of pages
    pdfio_obj_t   *page;            // Current page
    pdfio_dict_t  *dict;            // Current page dictionary
    size_t streams_count;
    
    for (i = 0, count = pdfioFileGetNumPages(pdf); i < count; i ++)
    {
        page = pdfioFileGetPage(pdf, i);
        dict = pdfioObjGetDict(page);
        streams_count = pdfioPageGetNumStreams(page); 
        UtilityFunctions::print("Number of streams for page ", i, ": ", streams_count);
        
    }
    
}



GDExample::GDExample() {
    //Initialize any variables here.
    time_passed = 0.0;
    pdf = pdfioFileOpen("/home/rich/_testPDFs/VCR2L.pdf", NULL, NULL, NULL, NULL);
    if (!pdf){
        UtilityFunctions::print("Did not load PDF.");
    }
    else {
        _pdfTest(pdf);
    }
    
}


GDExample::~GDExample() {
    if (pdf) {
        pdfioFileClose(pdf);
        UtilityFunctions::print("PDF file closed.");
    }
}

Variant GDExample::testExportFunc(){
    UtilityFunctions::print("Printed from gdextension!");
    Dictionary testdata;
    //testdata = Variant(Variant::DICTIONARY);
    testdata[Variant("Among us")] = "Fortnite";
    return testdata;

}

void GDExample::_process(double delta) {
    time_passed += delta;
    
    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));
    
    set_position(new_position);
    
}