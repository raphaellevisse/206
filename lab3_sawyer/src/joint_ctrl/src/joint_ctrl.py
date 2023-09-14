#! /usr/bin/env python
# Copyright (c) 2013-2018, Rethink Robotics Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
SDK Joint Position Example: keyboard
"""
import argparse

import rospy

import intera_interface
import intera_external_devices

from intera_interface import CHECK_VERSION
import numpy as np

def map_keyboard(side):
    limb = intera_interface.Limb(side)

    try:
        gripper = intera_interface.Gripper(side + '_gripper')
    except:
        has_gripper = False
        rospy.loginfo("The electric gripper is not detected on the robot.")
    else:
        has_gripper = True

    joints = limb.joint_names()

    def set_j(limb, angles):
        joint_command = {name:angle for name, angle in zip([joints[j] for j in range(7)], angles)}
        print("Executing" + str(joint_command))
        limb.set_joint_position_speed(0.3)
        limb.set_joint_positions(joint_command)

    def set_g(action):
        if has_gripper:
            if action == "close":
                gripper.close()
            elif action == "open":
                gripper.open()
            elif action == "calibrate":
                gripper.calibrate()

    bindings = {
        '1': (set_j, [limb, joints[0], 0.1], joints[0]+" increase"),
        'q': (set_j, [limb, joints[0], -0.1], joints[0]+" decrease"),
        '2': (set_j, [limb, joints[1], 0.1], joints[1]+" increase"),
        'w': (set_j, [limb, joints[1], -0.1], joints[1]+" decrease"),
        '3': (set_j, [limb, joints[2], 0.1], joints[2]+" increase"),
        'e': (set_j, [limb, joints[2], -0.1], joints[2]+" decrease"),
        '4': (set_j, [limb, joints[3], 0.1], joints[3]+" increase"),
        'r': (set_j, [limb, joints[3], -0.1], joints[3]+" decrease"),
        '5': (set_j, [limb, joints[4], 0.1], joints[4]+" increase"),
        't': (set_j, [limb, joints[4], -0.1], joints[4]+" decrease"),
        '6': (set_j, [limb, joints[5], 0.1], joints[5]+" increase"),
        'y': (set_j, [limb, joints[5], -0.1], joints[5]+" decrease"),
        '7': (set_j, [limb, joints[6], 0.1], joints[6]+" increase"),
        'u': (set_j, [limb, joints[6], -0.1], joints[6]+" decrease")
     }
    if has_gripper:
        bindings.update({
        '8': (set_g, "close", side+" gripper close"),
        'i': (set_g, "open", side+" gripper open"),
        '9': (set_g, "calibrate", side+" gripper calibrate")
        })
    done = False
    print("Controlling joints. Press ? for help, Esc to quit.")
    while not done and not rospy.is_shutdown():
        
        
        
        a = input("input 7 angles")
        angles = [float(i) for i in a.split()]

        if (len(angles) != 7):
            print("not 7 angles")

        else:
            diff = 1
            while (diff > 0.01):
                current = [limb.joint_angle(joint_name) for joint_name in joints]
                diff = np.linalg.norm(np.array(current) - np.array(angles))
                print("diff", diff)
                set_j(limb, angles)
                info = {joint_name : limb.joint_angle(joint_name) for joint_name in joints}
                print(info)
        
        info = {joint_name : limb.joint_angle(joint_name) for joint_name in joints}
        print(info)
        

def main():
    """RSDK Joint Position Example: Keyboard Control

    Use your dev machine's keyboard to control joint positions.

    Each key corresponds to increasing or decreasing the angle
    of a joint on Sawyer's arm. The increasing and descreasing
    are represented by number key and letter key next to the number.
    """
    epilog = """
See help inside the example with the '?' key for key bindings.
    """
    rp = intera_interface.RobotParams()
    valid_limbs = rp.get_limb_names()
    if not valid_limbs:
        rp.log_message(("Cannot detect any limb parameters on this robot. "
                        "Exiting."), "ERROR")
        return
    arg_fmt = argparse.RawDescriptionHelpFormatter
    parser = argparse.ArgumentParser(formatter_class=arg_fmt,
                                     description=main.__doc__,
                                     epilog=epilog)
    parser.add_argument(
        "-l", "--limb", dest="limb", default=valid_limbs[0],
        choices=valid_limbs,
        help="Limb on which to run the joint position keyboard example"
    )
    args = parser.parse_args(rospy.myargv()[1:])

    print("Initializing node... ")
    rospy.init_node("sdk_joint_position_keyboard")
    print("Getting robot state... ")
    rs = intera_interface.RobotEnable(CHECK_VERSION)
    init_state = rs.state().enabled

    def clean_shutdown():
        print("\nExiting example.")

    rospy.on_shutdown(clean_shutdown)

    rospy.loginfo("Enabling robot...")
    rs.enable()
    map_keyboard(args.limb)
    print("Done.")


if __name__ == '__main__':
    main()
