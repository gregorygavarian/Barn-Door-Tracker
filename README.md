Apologies for some of the formatting, this was originally written in a Word document with proper math formatting.

As a preface, I would suggest reading up on what a barn door tracker is on Wikipedia, and pay special attention during the Mount Design Alternatives section, specifically the portion on _tangent error_.  https://en.wikipedia.org/wiki/Barn_door_tracker

Without getting too much into it, a barn door tracker is used to take long exposure photographs of the night sky without the stars becoming smears in the final image.  The sky appears to rotate throughout the night.  If you place a camera on a static tripod pointed towards the sky and keep the shutter open, after too long, the movement of the stars will become apparent in the image.  This can be compensated for by using a shorter exposure, with the tradeoff that you'll capture less stellar detail.

Dedicated astronomical mounts are made to rotate it's payload (either a telescope, camera, or telescope-mounted camera) in sync with the night sky.  There are two main varieties: the German equatorial mount, which is more accurate but requires more care and attention to get working correctly, and is generally more expensive, or the more user-friendly and less expensive, but less accurate, Alt-Azimuth mounts.

Each have their tradeoffs, but the common link between both is that they are large and expensive, ranging from a few hundred dollars for hobby-grade units, to thousands of dollars for enthusiast-grade units.  An alternative is to use a "barn door" tracker.  The barn door tracker is nothing more than two hinged pieces of wood, with one piece mounted horizontally on a tripod, and the other piece resting on top of it.  A camera is mounted on the top piece of wood, and aimed towards the sky.  The tracker has a long screw opposite the hinged end, which, when rotated, will press against the inside surface of the top piece of wood, causing it to rise. 

![image](https://user-images.githubusercontent.com/80729542/111400970-c7349980-869e-11eb-93db-5cf57411d9bd.png)

After pointing the hinge towards the North Celestial Pole (the axis through which the sky apperas to rotate), if the screw is rotated at the correct rate, the camera will be lifted roughly in conjunction with the rotation of the sky, compensating for it to a degree.  Some enthusiasts have even gone as far as adjusting the design of the mount, or coupling a simple clock motor to the screw to increase accuracy.  The drawbacks of both of these methods are that they are limited to the amount of time they can track for due to the fact that the screw is driven linearly when an angular rotation is needed.  For short tracking periods, the tracker works reasonably well.  The small-angle approximation tells us that the sine of the rotation angle (the length that the screw is driven) is approximately equal to the rotation angle itself.  So, for short durations, the difference is negligible.  But as the rotation angle increases, this difference becomes significant, and the stars in the image would become progressively more smeared.  This is what the tangential error is referring to.  The Wikipedia article states that "This type of mount is good for approximately 5–10 minutes before tracking errors become evident when using a 50 mm lens."

To truly compensate for angular rotation by using linear motion, one would need to progressively increase the speed of the screw.  By using some math, we can calculate how fast one would need to rotate that screw.

The aim of the barn door tracker is to make it so that the angle θ_BD increases at the same rate the sky appears to rotate as closely as possible.  The angle can be described by the equation:

θ_BD=arctan⁡〖b/a〗

The value of b is the linear distance that the screw is driven, and the value a is the distance from the hinge to the screw.  The value b is changed by the rotation of the bolt, so it is appropriate to describe b as a function of time.

b=b(t)

Since b is moving linearly upwards, the length can be written as the linear velocity multiplied by time.

b(t)=v_bolt t

The linear velocity of the bolt is a function of the linear thread density τ, the number of rotations per second n, a conversion factor f=1 thread/rotation, and time t.

v_bolt=1/τ⋅n  rotations/s⋅1  thread/rotation=nf/τ
∴b(t)=nft/τ
∴θ_BD=arctan⁡〖nft/τa〗

The actual rotational speed of the sky can be calculated by considering that the Earth turns 360 degrees in 24 hours or 86,400 seconds.  It would be more appropriate to use the length of a sidereal day, ≈86,150 seconds, but 86,400 seconds makes the math simpler, and the difference is negligible.

ω_sky=θ_sky/t=(360°)/(24 h)=(360°)/(86,400 s)=(1°)/(240 s)

With this information, we can describe the angle the stars have moved during any time t.

θ_sky=(1°)/(240 s) t

Now with expressions for both angles, we can set both equal to each other.

θ_BD=θ_sky
arctan⁡〖nft/τa〗=(1°)/(240 s) t

With some simple algebraic manipulation:

nft/τa=tan⁡[(1°)/(240 s) t]
n=(τa )/ft  tan⁡[(1°)/(240 s) t]

This formula gives rotations per second, but it can be changed to rotations per minute (RPM) by multiplying by 60.

n_RPM=60 (τa )/ft  tan⁡[(1°)/(240 s) t]

And since |f|=1,

n_RPM=60 (τa )/t  tan⁡[(1°)/(240 s) t]

![image](https://user-images.githubusercontent.com/80729542/111401181-27c3d680-869f-11eb-935c-6fd4dd310568.png)
Figure 1: Plot showing the necessary RPM to match the rotational rate of the sky.  This assumes a ¼”-20 bolt and 12 inches from hinge to bolt.

In Figure 1, the rotation rate is just above 1 RPM.  However, it would be easier to change the design of the tracker such that n is a round number.  An obvious choice would be n=1 RPM.  Perhaps the easiest parameter to change would be the position of the bolt, a, along the horizontal face.  The number of rotations per minute varies with time, so there’s no steadfast length we can choose which will yield n=1 RPM for all values of t.  But we can choose a value for a where the average is 1 RPM.

For a time-varying function such as this, the average is equal to:

1/(b-a)  ∫_a^b▒n(t)dt

If we choose a reasonable exposure time, say, 5 minutes (from 0 to 300 seconds), the integrand will be:

1 RPM=1/(300-0)⋅60τa ∫_0^300▒〖tan⁡[(1°)/(240 s) t]/t dt〗=0.087a
a=11.46 inches

Or, for those without the means to perform the integral above, there is a much simpler formula one can use.

n_RPM=τaπ/720

For n=1 RPM,

a=720/τπ
