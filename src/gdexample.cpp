#include "gdexample.h"
#include <pdfio.h>
//#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
}

GDExample::GDExample() {
    //Initialize any variables here.
    time_passed = 0.0;
    pdf = pdfioFileOpen("/home/rich/Projects/gd-pdf/demo/_testPDFs/VCR2L.pdf", NULL, NULL, NULL, NULL);
    if (pdf){
        pdfio_obj_t *pdf_page = pdfioFileGetPage(pdf, 0);
        if (pdf_page){
            UtilityFunctions::print("PDF Page loaded.");


        }
        UtilityFunctions::print("PDF Pointer address: ", (uint64_t)pdf);
    }
    else {
        UtilityFunctions::print("Did not load PDF.");
    }

}

GDExample::~GDExample() {
    if (pdf) {
        pdfioFileClose(pdf);
        UtilityFunctions::print("PDF file closed.");
    }
}

void GDExample::_process(double delta) {
    time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    set_position(new_position);
    
}
