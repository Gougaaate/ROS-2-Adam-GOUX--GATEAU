from launch import LaunchDescription
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

# Fonction appelé par ros2 launch pour avoir la liste des nodes à lancer
def generate_launch_description():
    nodeSimulation = Node(
        package='tp2',  # nom du package
        namespace='boat1',
        executable='nodeSimulation',  # nom de l'executable
        name='nodeSimulation',  # nom du node lors du lancement
        parameters=[config_boat_1]  # variable contenant les paramètres chargés précédemment
    )

    node2 = Node(
    package='tp1',
    namespace='',
    executable='nodeB',
    name='node_B'
    )

# retour de la fonction avec la liste des nodes à lancer
    return LaunchDescription([
    node1,
    node2
    ])