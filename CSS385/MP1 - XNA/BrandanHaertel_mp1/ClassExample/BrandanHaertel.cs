using System;

namespace BrandanHaertel_NameSpace
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            using (BallGame game = new BallGame())
            {
                game.Run();
            }
        }
    }
}

