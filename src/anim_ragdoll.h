#pragma once

#include "skeletal_mesh.h"
#include <vector>
#include <PxPhysicsAPI.h>

using namespace physx;

struct Ragdoll
{
    std::vector<PxRigidDynamic*> m_rigid_bodies;
    std::vector<glm::vec3>       m_relative_joint_pos;
    std::vector<glm::quat>       m_original_body_rotations;

    std::vector<glm::vec3> m_body_pos_relative_to_joint;
    std::vector<glm::quat> m_original_joint_rotations;

    PxRigidDynamic* find_recent_body(uint32_t idx, Skeleton* skeleton, uint32_t& chosen_idx);
    void            set_kinematic(bool state);
};

inline PxQuat to_quat(const glm::quat& q)
{
    return PxQuat(q.x, q.y, q.z, q.w);
}

inline glm::quat to_quat(const PxQuat& q)
{
    return glm::quat(q.w, q.x, q.y, q.z);
}

inline PxVec3 to_vec3(const glm::vec3& vec3)
{
    return PxVec3(vec3.x, vec3.y, vec3.z);
}

inline glm::vec3 to_vec3(const PxVec3& vec3)
{
    return glm::vec3(vec3.x, vec3.y, vec3.z);
}

inline PxMat44 to_mat44(const glm::mat4& mat)
{
    PxMat44 newMat;

    newMat[0][0] = mat[0][0];
    newMat[0][1] = mat[0][1];
    newMat[0][2] = mat[0][2];
    newMat[0][3] = mat[0][3];

    newMat[1][0] = mat[1][0];
    newMat[1][1] = mat[1][1];
    newMat[1][2] = mat[1][2];
    newMat[1][3] = mat[1][3];

    newMat[2][0] = mat[2][0];
    newMat[2][1] = mat[2][1];
    newMat[2][2] = mat[2][2];
    newMat[2][3] = mat[2][3];

    newMat[3][0] = mat[3][0];
    newMat[3][1] = mat[3][1];
    newMat[3][2] = mat[3][2];
    newMat[3][3] = mat[3][3];

    return newMat;
}

inline glm::mat4 to_mat4(const PxMat44& mat)
{
    glm::mat4 newMat;

    newMat[0][0] = mat[0][0];
    newMat[0][1] = mat[0][1];
    newMat[0][2] = mat[0][2];
    newMat[0][3] = mat[0][3];

    newMat[1][0] = mat[1][0];
    newMat[1][1] = mat[1][1];
    newMat[1][2] = mat[1][2];
    newMat[1][3] = mat[1][3];

    newMat[2][0] = mat[2][0];
    newMat[2][1] = mat[2][1];
    newMat[2][2] = mat[2][2];
    newMat[2][3] = mat[2][3];

    newMat[3][0] = mat[3][0];
    newMat[3][1] = mat[3][1];
    newMat[3][2] = mat[3][2];
    newMat[3][3] = mat[3][3];

    return newMat;
}

class AnimRagdoll
{
public:
    AnimRagdoll(Skeleton* skeleton);
    ~AnimRagdoll();
    PoseTransforms* apply(Ragdoll* ragdoll, glm::mat4 model_scale, glm::mat4 model_rotation);

private:
    Skeleton*      m_skeleton;
    PoseTransforms m_transforms;
};
