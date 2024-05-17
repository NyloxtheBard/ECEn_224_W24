# Image

## Experience Summary

### How many hours did it take to complete assignment?
3 hours
### What did you enjoy about this lab?
I enjoyed looking at all of the stuff in image.c and piecing together the best way to implement the masking of the images. I also found it good practice at attempting to implement masking of bits, especially with the pixels. 

### What were the major challenges you had with this lab? Try to be as detailed as possible.
Figuring out the best way to mask the bits was hard for me, along with figuring out the order of the steps that had to be taken in order for the manipulation of the images to be generated properly. I also found the instructions to be somewhat vague compared to last labs, making this one more ambiguous as to how we go about it. It also was harder as I had to analyze code that had already been implemented into the lab, and figuring out how to use that when creating my functions and setting up my main.c

## Lab Specific Tasks

### Remove Color Channel
1. Save the GREEN masked image as `green_mask.bmp`

![green](./green_mask.bmp)

2. Save the BLUE masked image as `blue_mask.bmp`

![blue](./blue_mask.bmp)

3. Save the RED masked image as `red_mask.bmp`

![red](./red_mask.bmp)

4. What was your method for masking out/turning off the appropriate channel values?

I used a switch statement to determine which color I was working on based on what was passed in to the function to filter out. Then, I used 3 cases, one for each of the colors that we were working with, being red, blue and green. I then used a for loop to iterate over each pixel in the pxl_data array to select the color. In order to have the loop work with the bmp data, I had to divied the pxl_data_size by three, as the values given were in bytes, and in order to read the individual pixels I divided it by three as the pixels have three bytes of memory each, giving me the exact number of pixels. From the iterator in the for loop, I then indexed through the bmp->pxl_data array, and then multipled that value by 3 to get the blue color, added one to that value to get green, and added one to that value to get red pixel value. Using this obtained index value, I would then take the location and bitmask it using the hex value 0x00 and the bitwise AND operator. This allowed me to bitmaske the value and reassign it to the bmp->pixl_data_array at the index. The loop would then run until the entire pxl_data array had been iterated over, masking all of the specified color and removing it from the image. 

5. Why did you choose to do it this way?

I chose to do it this way as it was one of the simplest methods of masking and processing the image pixels that I could come up with. It also operated as a very logical and efficient way of parsing through each of these values as well. Once I had established the basic case of how to first iterate through every pixel in the image, modify the specified color within the pixel, and then reassign the modified pixel, it was an easy copy and paste for each of my three cases, only changing what color was being looked at and modified. This allowed me to follow these steps as closely as possible, without worrying about causing any errors or issues due to the simplicity of the method. 

### Grayscale
6. Save the grayscaled image as `grayscale.bmp`

![grayscale](./grayscale.bmp)

### OR Filter
7. Save the OR blurred image as `or_filter.bmp`

![or_filter](./or_filter.bmp)

8. Explain why you think the image looks the way it does after applying the or filter.

The reason I believe that the image looks slightly distorted after applying the OR filter is due to the varying values the program reads in and bitwise ORs together. Due to each color being a single byte, there are a total of 8 bits that can be changed and each pixel has a different color value than the one above or below it. When these values are OR'd together, they then create a similar, but lighter color than what the original pixel was. THis is what causes the image to have different values, and also causes the slight distortion of the colors used, as when the colors vary enough it will cause a signficiant change to the modified pixel.
