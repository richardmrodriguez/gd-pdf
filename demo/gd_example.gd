extends GDExample


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	var result = testExportFunc()
	print(result)
	#var pdfbytes_result = printRawPDFBytes("TestString")
