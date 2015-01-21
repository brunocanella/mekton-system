#ifndef SERVOS_HPP_
#define SERVOS_HPP_

#include "servo.hpp"
#include "head.hpp"
#include "torso.hpp"
#include "arm.hpp"
#include "leg.hpp"
#include "tail.hpp"
#include "wing.hpp"
#include "pod.hpp"

#include <vector>

namespace mekton {

typedef std::vector<PtrServo> Servos;

} /*namespace mekton*/

#endif // SERVOS_HPP_
