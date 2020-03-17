pipeline {
    agent any

    stages {
        stage('Clone sources') {
            steps {
                echo 'Cloning sources..'
                git url: 'https://github.com/simoc/linear-algebra.git'
            }
        }
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'make'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh './gtest-la --gtest_output=xml:test_detail.xml'
                
                step([
                    $class: 'XUnitPublisher',
                    tools: [[ $class: 'GoogleTestType', pattern: 'test_detail.xml' ]]
                    ])
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
