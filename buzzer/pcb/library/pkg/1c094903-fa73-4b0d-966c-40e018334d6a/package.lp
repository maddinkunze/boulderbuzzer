(librepcb_package 1c094903-fa73-4b0d-966c-40e018334d6a
 (name "PLCC6")
 (description "Footprint for the PLCC6 Package with the following (size) variants:\n - 5050 (5mmx5mm) as descibed in https://www.media.highlight-led.de/products/documents/pdf/76600026.pdf\n - 6050 (6mmx5mm) as described in https://docs.rs-online.com/5d1c/0900766b814b7b62.pdf\n\nThere is an additional variant of the 5050 variant where the pins are not embedded but seperate legs, as described here https://www.lumex.com/led-smd-PLCC6+5050.html\n\nAlternative Names:\n - 5050-default: WS2812\n - 6050-default: CLP6C-FKB")
 (keywords "PLCC6,5050,SMD5050,RGB5050,WS2812,CLP6C-FKB")
 (author "Martin Kunze")
 (version "0.1")
 (created 2023-06-26T10:38:19Z)
 (deprecated false)
 (category 0764a19f-0b33-4927-906a-f4d6c522841d)
 (pad 378ea984-4a60-4a86-b488-fe6333d3eb42 (name "6"))
 (pad 28163a36-13ca-4cf5-9823-d2a4720c1966 (name "4"))
 (pad e892a50e-4f2e-4ba5-b595-7bfd6457c94e (name "2"))
 (pad 29a38e15-06ca-4ba0-8e8c-5596961ab780 (name "5"))
 (pad 436f31a3-bf51-4582-b098-5cf4696cfe17 (name "3"))
 (pad 9f6e27f4-7476-4b2d-bd36-f4ab00a705c5 (name "1"))
 (footprint 7b7d2669-638c-4772-b144-93572729d2a1
  (name "5050-default")
  (description "")
  (pad 378ea984-4a60-4a86-b488-fe6333d3eb42 (side top) (shape rect)
   (position -2.3 -1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 28163a36-13ca-4cf5-9823-d2a4720c1966 (side top) (shape rect)
   (position -2.3 1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad e892a50e-4f2e-4ba5-b595-7bfd6457c94e (side top) (shape rect)
   (position 2.3 0.0) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 29a38e15-06ca-4ba0-8e8c-5596961ab780 (side top) (shape rect)
   (position -2.3 0.0) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 436f31a3-bf51-4582-b098-5cf4696cfe17 (side top) (shape rect)
   (position 2.3 1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 9f6e27f4-7476-4b2d-bd36-f4ab00a705c5 (side top) (shape rect)
   (position 2.3 -1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (polygon 4e906554-3bd0-488c-b73b-34a7263fd7b3 (layer top_documentation)
   (width 0.1) (fill false) (grab_area true)
   (vertex (position -2.5 2.5) (angle 0.0))
   (vertex (position 2.5 2.5) (angle 0.0))
   (vertex (position 2.5 -2.5) (angle 0.0))
   (vertex (position -2.5 -2.5) (angle 0.0))
   (vertex (position -2.5 2.5) (angle 0.0))
  )
  (polygon f1166d28-eaa2-45a3-924e-0b12084fe18d (layer top_documentation)
   (width 0.1) (fill false) (grab_area false)
   (vertex (position 2.0 -2.5) (angle 0.0))
   (vertex (position 2.5 -2.0) (angle 0.0))
  )
  (polygon f65de8d0-eb69-4c0b-8023-ba0141cb9c3c (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position 2.7 2.4) (angle 0.0))
   (vertex (position 2.7 2.7) (angle 0.0))
   (vertex (position 2.4 2.7) (angle 0.0))
  )
  (polygon 6247d429-619b-441c-aee5-68acbe4b82d1 (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position -2.7 2.4) (angle 0.0))
   (vertex (position -2.7 2.7) (angle 0.0))
   (vertex (position -2.4 2.7) (angle 0.0))
  )
  (polygon 95023b2b-dcf3-4618-8e6b-180cc9f8ce25 (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position -2.7 -2.4) (angle 0.0))
   (vertex (position -2.7 -2.7) (angle 0.0))
   (vertex (position -2.4 -2.7) (angle 0.0))
  )
  (polygon 54aa866c-4515-49d8-b79c-a9cf64a6d3f8 (layer top_placement)
   (width 0.2) (fill true) (grab_area false)
   (vertex (position 3.0 -2.4) (angle 0.0))
   (vertex (position 3.0 -3.0) (angle 0.0))
   (vertex (position 2.4 -3.0) (angle 0.0))
   (vertex (position 3.0 -2.4) (angle 0.0))
  )
  (circle a5bddcf1-9bf7-467f-81e1-38853de048a7 (layer top_documentation)
   (width 0.1) (fill false) (grab_area false) (diameter 3.7) (position 0.0 0.0)
  )
  (stroke_text bc9f5737-7e60-476e-943e-94963af45bf9 (layer top_names)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center bottom) (position 0.0 3.4) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{NAME}}")
  )
  (stroke_text a6d8b057-47e6-4cbc-a986-877cb06f187a (layer top_values)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center top) (position 0.0 -3.5) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{VALUE}}")
  )
 )
 (footprint 67013e1a-e654-4c27-be30-1a427b574f3e
  (name "5050-pinlegs")
  (description "")
  (pad 378ea984-4a60-4a86-b488-fe6333d3eb42 (side top) (shape rect)
   (position -3.7 -1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 28163a36-13ca-4cf5-9823-d2a4720c1966 (side top) (shape rect)
   (position -3.7 1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad e892a50e-4f2e-4ba5-b595-7bfd6457c94e (side top) (shape rect)
   (position 3.7 0.0) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 29a38e15-06ca-4ba0-8e8c-5596961ab780 (side top) (shape rect)
   (position -3.7 0.0) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 436f31a3-bf51-4582-b098-5cf4696cfe17 (side top) (shape rect)
   (position 3.7 1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (pad 9f6e27f4-7476-4b2d-bd36-f4ab00a705c5 (side top) (shape rect)
   (position 3.7 -1.6) (rotation 0.0) (size 1.6 1.1) (drill 0.0)
  )
  (polygon 4e906554-3bd0-488c-b73b-34a7263fd7b3 (layer top_documentation)
   (width 0.1) (fill false) (grab_area true)
   (vertex (position -2.5 2.5) (angle 0.0))
   (vertex (position 2.5 2.5) (angle 0.0))
   (vertex (position 2.5 -2.5) (angle 0.0))
   (vertex (position -2.5 -2.5) (angle 0.0))
   (vertex (position -2.5 2.5) (angle 0.0))
  )
  (polygon f1166d28-eaa2-45a3-924e-0b12084fe18d (layer top_documentation)
   (width 0.1) (fill false) (grab_area false)
   (vertex (position 2.0 -2.5) (angle 0.0))
   (vertex (position 2.5 -2.0) (angle 0.0))
  )
  (polygon f65de8d0-eb69-4c0b-8023-ba0141cb9c3c (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position 2.7 2.4) (angle 0.0))
   (vertex (position 2.7 2.7) (angle 0.0))
   (vertex (position 2.4 2.7) (angle 0.0))
  )
  (polygon 6247d429-619b-441c-aee5-68acbe4b82d1 (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position -2.7 2.4) (angle 0.0))
   (vertex (position -2.7 2.7) (angle 0.0))
   (vertex (position -2.4 2.7) (angle 0.0))
  )
  (polygon 54aa866c-4515-49d8-b79c-a9cf64a6d3f8 (layer top_placement)
   (width 0.2) (fill true) (grab_area false)
   (vertex (position 3.0 -2.4) (angle 0.0))
   (vertex (position 3.0 -3.0) (angle 0.0))
   (vertex (position 2.4 -3.0) (angle 0.0))
   (vertex (position 3.0 -2.4) (angle 0.0))
  )
  (polygon 25a989b2-ef26-46f9-8736-fb5220dd6e65 (layer top_placement)
   (width 0.2) (fill true) (grab_area false)
   (vertex (position -3.0 -2.4) (angle 0.0))
   (vertex (position -3.0 -3.0) (angle 0.0))
   (vertex (position -2.4 -3.0) (angle 0.0))
   (vertex (position -3.0 -2.4) (angle 0.0))
  )
  (circle a5bddcf1-9bf7-467f-81e1-38853de048a7 (layer top_documentation)
   (width 0.1) (fill false) (grab_area false) (diameter 3.7) (position 0.0 0.0)
  )
  (stroke_text 3ce82dc7-aeba-4573-a37d-ab0eaaf0f3c9 (layer top_names)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center bottom) (position 0.0 3.4) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{NAME}}")
  )
  (stroke_text b408ba36-714f-48d1-9678-9d2af4f6429a (layer top_values)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center top) (position 0.0 -3.5) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{VALUE}}")
  )
 )
 (footprint 5f30b273-1199-4a1d-857c-2761dcffcd0d
  (name "6050-default")
  (description "")
  (pad 378ea984-4a60-4a86-b488-fe6333d3eb42 (side top) (shape rect)
   (position -2.3 -2.1) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (pad 29a38e15-06ca-4ba0-8e8c-5596961ab780 (side top) (shape rect)
   (position -2.3 0.0) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (pad 9f6e27f4-7476-4b2d-bd36-f4ab00a705c5 (side top) (shape rect)
   (position 2.3 -2.1) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (pad 28163a36-13ca-4cf5-9823-d2a4720c1966 (side top) (shape rect)
   (position -2.3 2.1) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (pad 436f31a3-bf51-4582-b098-5cf4696cfe17 (side top) (shape rect)
   (position 2.3 2.1) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (pad e892a50e-4f2e-4ba5-b595-7bfd6457c94e (side top) (shape rect)
   (position 2.3 0.0) (rotation 0.0) (size 2.0 1.5) (drill 0.0)
  )
  (polygon 6c5cf50a-d7ff-4f10-8335-4f710a95fb70 (layer top_documentation)
   (width 0.1) (fill false) (grab_area true)
   (vertex (position -2.5 3.0) (angle 0.0))
   (vertex (position 2.5 3.0) (angle 0.0))
   (vertex (position 2.5 -3.0) (angle 0.0))
   (vertex (position -2.5 -3.0) (angle 0.0))
   (vertex (position -2.5 3.0) (angle 0.0))
  )
  (polygon e4529a1c-3baa-4e3f-8fcc-2e7e30d24a77 (layer top_placement)
   (width 0.2) (fill true) (grab_area false)
   (vertex (position 3.0 -3.1) (angle 0.0))
   (vertex (position 3.0 -3.5) (angle 0.0))
   (vertex (position 2.6 -3.5) (angle 0.0))
   (vertex (position 3.0 -3.1) (angle 0.0))
  )
  (polygon 06eb222e-e192-48a0-8de8-a7050428a4ea (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position 2.7 3.1) (angle 0.0))
   (vertex (position 2.7 3.2) (angle 0.0))
   (vertex (position 2.4 3.2) (angle 0.0))
  )
  (polygon 458f3da8-ff22-4de2-8518-eb218c7527a7 (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position -2.7 3.1) (angle 0.0))
   (vertex (position -2.7 3.2) (angle 0.0))
   (vertex (position -2.4 3.2) (angle 0.0))
  )
  (polygon c6428f92-18fd-4f38-9dba-8b9abd6498a0 (layer top_documentation)
   (width 0.1) (fill false) (grab_area false)
   (vertex (position 2.0 -3.0) (angle 0.0))
   (vertex (position 2.5 -2.5) (angle 0.0))
  )
  (polygon 9d599913-d90f-4fd5-86b1-bb8fc7afdb6e (layer top_placement)
   (width 0.2) (fill false) (grab_area false)
   (vertex (position -2.7 -3.1) (angle 0.0))
   (vertex (position -2.7 -3.2) (angle 0.0))
   (vertex (position -2.4 -3.2) (angle 0.0))
  )
  (circle dd1d098d-049e-43ff-ba04-f11dd931653d (layer top_documentation)
   (width 0.1) (fill false) (grab_area false) (diameter 3.7) (position 0.0 0.0)
  )
  (stroke_text 6d663cd3-defc-48b7-976d-e2e1bc138abf (layer top_names)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center bottom) (position 0.0 4.0) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{NAME}}")
  )
  (stroke_text 53711241-89c8-41a1-b18a-0678df9b5a0f (layer top_values)
   (height 1.0) (stroke_width 0.2) (letter_spacing auto) (line_spacing auto)
   (align center top) (position 0.0 -4.1) (rotation 0.0)
   (auto_rotate true) (mirror false) (value "{{VALUE}}")
  )
 )
)
