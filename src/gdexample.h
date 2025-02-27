#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <pdfio.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

    class GDExample : public Sprite2D {
        GDCLASS(GDExample, Sprite2D);

    private:
        double time_passed;
        pdfio_file_t *pdf;

    protected: static void _bind_methods();

    public:
        GDExample();
        ~GDExample();
        void _process(double delta) override;
        Variant testExportFunc();
        Variant printRawPDFBytes(String filepath);
    };
}

#endif
