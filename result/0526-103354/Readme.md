# Daily Evaluation 26/05 - 10:33:54
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 23/23 :  100%
## Detail by Feature
| Feature     | Score       | Missed tests | Stdout |
| :---------- | :---------- | :----------- | :----- |
| dimension   | 4/4 :  100% |              |        |
| first_pixel | 5/5 :  100% |              |        |
| tenth_pixel | 5/5 :  100% |              |        |
| second_line | 5/5 :  100% |              |        |
| print_pixel | 4/4 :  100% |              |        |

# Milestone  statistiques
Score : 18/26 :  69%
## Detail by Feature
| Feature         | Score       | Missed tests                                          | Stdout                            |
| :-------------- | :---------- | :---------------------------------------------------- | :-------------------------------- |
| max_pixel       | 4/4 :  100% |                                                       |                                   |
| min_pixel       | 2/4 :  50%  | Min Pixel at 6 5<br>Min Pixel at 3 4                  | min_pixel (0, 0): 132, 132, 132<… |
| min_component R | 3/3 :  100% |                                                       |                                   |
| min_component G | 3/3 :  100% |                                                       |                                   |
| min_component B | 3/3 :  100% |                                                       |                                   |
| max_component R | 1/3 :  33%  | Max Component R of white 8x8<br>Max Component 2 0 255 | max_component R (0, 0): 0<br>max… |
| max_component G | 1/3 :  33%  | Max Component G of white 8x8<br>Max Component 2 0 255 | max_component G (0, 0): 0<br>max… |
| max_component B | 1/3 :  33%  | Max Component B of white 8x8<br>Max Component 2 0 255 | max_component B (0, 0): 0<br>max… |

# Milestone  colors
Score : 8.68/35 :  24%
## Detail by Feature
| Feature              | Score                       | Missed tests                                                                                                                                              | Stdout           |
| :------------------- | :-------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100%                 |                                                                                                                                                           |                  |
| color_blue           | 3.6799999999999997/5 :  73% | Convert white Image to BLUE                                                                                                                               |                  |
| color_green          | 0/5 :  0%                   | Convert red image to GREEN<br>Convert blue image to GREEN<br>Convert green Image to GREEN<br>Convert white Image to GREEN<br>convert black Image to GREEN | <br><br><br><br> |
| color_gray           | 0/5 :  0%                   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |
| color_invert         | 0/5 :  0%                   | Invert red image<br>Invert blue image<br>Invert green Image<br>Invert white Image<br>Invert black Image                                                   | <br><br><br><br> |
| color_gray_luminance | 0/5 :  0%                   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |
| color_desaturate     | 0/5 :  0%                   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |

# Milestone  transform
Score : 0/15 :  0%
## Detail by Feature
| Feature           | Score     | Missed tests                                                   | Stdout   |
| :---------------- | :-------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| rotate_acw        | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| mirror_horizontal | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

