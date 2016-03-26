import skywriter
import signal
import OSC

c = OSC.OSCClient()
c.connect(('10.42.0.1', 6448)) 

some_value = 5000
v = 1

#@skywriter.move()
#def move(x, y, z):
  #print( x, y, z )
  #oscmsg = OSC.OSCMessage()
  #oscmsg.setAddress("/wek/inputs")
  #oscmsg.append(x)
  #oscmsg.append(y)
  #oscmsg.append(z)
  #c.send(oscmsg)


@skywriter.flick()
def flick(start,finish):
  print('Got a flick!', start, finish)
  oscmsg = OSC.OSCMessage()
  oscmsg.setAddress("/swipe")
  #oscmsg.append(start)
  if start == "west" and finish == "east":
  	oscmsg.append("right")
  if start == "east" and finish == "west":
  	oscmsg.append("left")
  if start == "north" and finish == "south":
  	oscmsg.setAddress("/keyTap")

  c.send(oscmsg)


@skywriter.airwheel()
def spinny(delta):
  global some_value
  some_value += delta
  if some_value < 0:
  	some_value = 0
  if some_value > 10000:
    some_value = 10000
  print('Airwheel:', some_value/100)
  oscmsg = OSC.OSCMessage()
  oscmsg.setAddress("/circle")
  oscmsg.append(some_value/100)
  c.send(oscmsg)

@skywriter.double_tap()
def doubletap(position):
  print('Double tap!', position)
  oscmsg = OSC.OSCMessage()
  oscmsg.setAddress("/doubletap")
  oscmsg.append(position)
  c.send(oscmsg)

@skywriter.tap()
def tap(position):
  print('Tap!', position)
  oscmsg = OSC.OSCMessage()
  oscmsg.setAddress("/keyTap")
  oscmsg.append(position)
  c.send(oscmsg)

@skywriter.touch()
def touch(position):
  print('Touch!', position)
  oscmsg = OSC.OSCMessage()
  oscmsg.setAddress("/touch")
  oscmsg.append(position)
  c.send(oscmsg)

signal.pause()
