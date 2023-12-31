// Generated by gencpp from file turtle_patrol/PatrolResponse.msg
// DO NOT EDIT!


#ifndef TURTLE_PATROL_MESSAGE_PATROLRESPONSE_H
#define TURTLE_PATROL_MESSAGE_PATROLRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Twist.h>

namespace turtle_patrol
{
template <class ContainerAllocator>
struct PatrolResponse_
{
  typedef PatrolResponse_<ContainerAllocator> Type;

  PatrolResponse_()
    : cmd()  {
    }
  PatrolResponse_(const ContainerAllocator& _alloc)
    : cmd(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _cmd_type;
  _cmd_type cmd;





  typedef boost::shared_ptr< ::turtle_patrol::PatrolResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtle_patrol::PatrolResponse_<ContainerAllocator> const> ConstPtr;

}; // struct PatrolResponse_

typedef ::turtle_patrol::PatrolResponse_<std::allocator<void> > PatrolResponse;

typedef boost::shared_ptr< ::turtle_patrol::PatrolResponse > PatrolResponsePtr;
typedef boost::shared_ptr< ::turtle_patrol::PatrolResponse const> PatrolResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtle_patrol::PatrolResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtle_patrol::PatrolResponse_<ContainerAllocator1> & lhs, const ::turtle_patrol::PatrolResponse_<ContainerAllocator2> & rhs)
{
  return lhs.cmd == rhs.cmd;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtle_patrol::PatrolResponse_<ContainerAllocator1> & lhs, const ::turtle_patrol::PatrolResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtle_patrol

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_patrol::PatrolResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtle_patrol::PatrolResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_patrol::PatrolResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a0c47a2b42626c8e0bd2a277053c6c62";
  }

  static const char* value(const ::turtle_patrol::PatrolResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa0c47a2b42626c8eULL;
  static const uint64_t static_value2 = 0x0bd2a277053c6c62ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtle_patrol/PatrolResponse";
  }

  static const char* value(const ::turtle_patrol::PatrolResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Response message types\n"
"geometry_msgs/Twist cmd\n"
"\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::turtle_patrol::PatrolResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PatrolResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtle_patrol::PatrolResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtle_patrol::PatrolResponse_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.cmd);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLE_PATROL_MESSAGE_PATROLRESPONSE_H
